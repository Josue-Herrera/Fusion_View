
#ifdef WIN32
#include <Windows.h>
#endif // console Hide commands

#include <iostream>

#include "..\include\fusion_imgui.h"

#include "misc/freetype/imgui_freetype.h"
#include "misc/freetype/imgui_freetype.cpp"


/// <summary>
/// This code NEEDS a REDESIGN PLS HELP DANNY !! 
/// </summary>
namespace fv {
	static int width;
	static int height;
	static  ImVec4 clear_color = ImVec4(0.1f, 0.1f, 0.10f, 1.00f);

	void glfw_error_callbacks(int error, const char* description)
	{
		fprintf(stderr, "Glfw Error %d: %s\n", error, description);
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		fv::width = width;
		fv::height = height;
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
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		
		ImGui_ImplGlfw_InitForOpenGL(fv_window, true);
		const char* glsl_version = "#version 410";
		ImGui_ImplOpenGL3_Init(glsl_version);
	
		unsigned int flags = ImGuiFreeType::ForceAutoHint;
		io.Fonts->AddFontFromFileTTF("..\\..\\resources\\fonts\\Open_Sans\\OpenSans-SemiBold.ttf", 18.0f);
		ImGuiFreeType::BuildFontAtlas(io.Fonts, flags);
		

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

		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");
			// Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}



		// 3. Show another simple window.
		if (show_another_window)
		{
			ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				show_another_window = false;
			ImGui::End();
		}

	}

	bool Fusion_Imgui::shutdown()
	{
		return glfwWindowShouldClose(fv_window);
	}

	

	void Fusion_Imgui::end()
	{

		// Rendering
		ImGui::Render();
		glViewport(0, 0, fv::width, fv::height);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		//ImGui::UpdatePlatformWindows();
	}
}
