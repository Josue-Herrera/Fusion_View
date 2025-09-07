#include "app/fusion_imgui.h"

#ifdef WIN32
#include <Windows.h>
#endif

#include <iostream>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "panels/imgui_helper.h"

namespace fv {
	static int width;
	static int height;
	static ImVec4 clear_color = ImVec4(0.1f, 0.1f, 0.10f, 1.00f);

	void glfw_error_callbacks(int error, const char* description)
	{
		fprintf(stderr, "Glfw Error %d: %s\n", error, description);
	}

	void framebuffer_size_callback(GLFWwindow* window, int w, int h)
	{
		fv::width = w;
		fv::height = h;
		glViewport(0, 0, fv::width, fv::height);
	}

	Fusion_Imgui::Fusion_Imgui()
	{
#ifdef WIN32
		::ShowWindow(::GetConsoleWindow(), SW_HIDE);
#endif
		glfwSetErrorCallback(glfw_error_callbacks);

		if (!glfwInit()) {
			std::cout << " Failed to init GLFW " << std::endl;
			exit(0);
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if (fv_window = glfwCreateWindow(800, 600, "Fusion View", NULL, NULL); fv_window == NULL)
		{
			std::cout << "fv::window_view::createWindow() Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(fv_window);
		glfwSwapInterval(1);
		glfwSetFramebufferSizeCallback(fv_window, framebuffer_size_callback);

		gladLoadGL();

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

		ImGui_ImplGlfw_InitForOpenGL(fv_window, true);
		const char* glsl_version = "#version 410";
		ImGui_ImplOpenGL3_Init(glsl_version);

		unsigned int flags = ImGuiFreeTypeBuilderFlags_ForceAutoHint;
		io.Fonts->AddFontFromFileTTF("..\\..\\resources\\fonts\\Open_Sans\\OpenSans-SemiBold.ttf", 18.0f);
		io.Fonts->FontBuilderIO = ImGuiFreeType::GetBuilderForFreeType();
		io.Fonts->FontBuilderFlags = flags;
		io.Fonts->Build();
	}

	Fusion_Imgui::~Fusion_Imgui()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		glfwDestroyWindow(fv_window);
		glfwTerminate();
	}

	void Fusion_Imgui::start()
	{
		glfwPollEvents();
		glfwSwapBuffers(fv_window);
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void Fusion_Imgui::showDemo() {
		static bool show_demo_window = true;
		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);
	}

	bool Fusion_Imgui::shutdown()
	{
		return glfwWindowShouldClose(fv_window);
	}

	void Fusion_Imgui::end()
	{
		ImGui::Render();
		glViewport(0, 0, fv::width, fv::height);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}

