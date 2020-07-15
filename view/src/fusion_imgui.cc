#include "..\include\fusion_imgui.h"

#include "imgui.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

#include "window_view.h" 

namespace fv {
	Fusion_Imgui::Fusion_Imgui()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls

		// Setup Dear ImGui style
		ImGui::StyleColorsLight();
		auto fv_window = fv::window_view::get_window_view();
		ImGui_ImplGlfw_InitForOpenGL(fv_window.get_ptr(), true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}
	Fusion_Imgui::~Fusion_Imgui()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
	void Fusion_Imgui::start()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}
	void Fusion_Imgui::end()
	{
		ImGuiIO& io = ImGui::GetIO();
		auto fv_window = fv::window_view::get_window_view();
		io.DisplaySize = ImVec2(fv_window.width,fv_window.height);

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}
