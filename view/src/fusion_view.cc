#include "fusion_view.h"
#include "imgui.h"
#include "components.h"
#include <cmrc/cmrc.hpp>
#include <algorithm>
#include "imgui_helper.h"

CMRC_DECLARE(fv);

namespace fv {
	Fusion_View::Fusion_View()
	{
		imgui = new Fusion_Imgui();

		loadComponents();
		loadDarkStyle();
	}

	Fusion_View::~Fusion_View()
	{
		delete imgui;
	}

	void Fusion_View::run()
	{

		while (!imgui->shutdown()) {
			imgui->start();
			
			// Add a layer stack of IMGUI Functions organized in the appropriate order.
			// this is odd but still  good i think !! needs more redesign. Not satisfied with the code yet
			// but its working
			for ( auto component : gui_stack )
			{
				component->RenderGui();
			}
			//Example of how EZ it is.
			if (should_close)
				imgui->test_ForceShutdown();

			//Example -> you only need to call the Imgui Functions in here and you have to manage state in certain circumstances.
			imgui->showDemo();

			imgui->end();
		}
	}

	void Fusion_View::loadComponents() {

		Layer* mm = new Main_Menu(&should_close);
		gui_stack.PushGui(mm);
	}
	void Fusion_View::loadDarkStyle()
	{
	

		auto & style = ImGui::GetStyle();
		
		style.FrameRounding = 4.0f;
		
		// *** Main Settings *** 
		style.WindowPadding = { 10.0f, 4.0f };
		style.FramePadding = { 10.0f, 4.0f };
		style.ItemSpacing = { 9.0f, 6.0f };
		style.ItemInnerSpacing = { 5.0f, 4.0f };
		style.TouchExtraPadding = { 0.0f,0.0f };
		style.IndentSpacing = 20.0f;
		style.ScrollbarSize = 10.f;
		style.GrabMinSize = 11.0f;
		
		// *** Borders ***
		style.WindowBorderSize = 0.0f;
		style.ChildBorderSize = 0.0f;
		style.PopupBorderSize = 0.0f;

		// *** Rounding ***
		style.WindowRounding = 4.0f;
		style.ChildRounding = 4.0f;
		style.FrameRounding = 4.0f;
		style.PopupRounding = 4.0f;
		style.ScrollbarRounding = 4.0f;
		style.GrabRounding = 4.0f;
		style.TabRounding = 4.0f;

		// *** Alignment ***
		style.WindowMenuButtonPosition = ImGuiDir_Right;

		auto & colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.299f, 0.281f, 0.302f, 1.00f);// old color gonna use for dark MSW ImVec4(0.19f, 0.18f, 0.18f, 1.00f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.44f, 0.32f, 0.32f, 0.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.12f, 0.11f, 0.11f, 0.98f);
		colors[ImGuiCol_Border] = ImVec4(0.55f, 0.45f, 0.45f, 0.30f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.26f, 0.25f, 0.25f, 1.00f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.36f, 0.33f, 0.33f, 1.00f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.62f, 0.25f, 0.25f, 0.29f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.44f, 0.38f, 0.38f, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.37f, 0.37f, 0.37f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.77f, 0.76f, 0.76f, 0.51f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.30f, 0.26f, 0.26f, 1.00f); //old  ImVec4(0.09f, 0.08f, 0.08f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 0.80f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.49f, 0.49f, 0.49f, 0.80f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.58f, 0.48f, 0.48f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.61f, 0.55f, 0.55f, 0.91f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.76f, 0.60f, 0.60f, 0.80f);
		colors[ImGuiCol_Button] = ImVec4(0.73f, 0.51f, 0.51f, 0.40f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.73f, 0.51f, 0.51f, 0.62f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.73f, 0.26f, 0.23f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.82f, 0.78f, 0.78f, 0.31f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.38f, 0.36f, 0.36f, 0.67f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.60f, 0.53f, 0.53f, 1.00f);
		colors[ImGuiCol_Separator] = ImVec4(0.97f, 0.97f, 0.97f, 0.12f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.97f, 0.97f, 0.97f, 0.12f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.97f, 0.97f, 0.97f, 0.12f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.80f, 0.80f, 0.80f, 0.56f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.98f, 0.26f, 0.26f, 0.67f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.98f, 0.26f, 0.26f, 0.95f);
		colors[ImGuiCol_Tab] = ImVec4(0.32f, 0.32f, 0.32f, 0.93f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.76f, 0.45f, 0.45f, 0.80f);
		colors[ImGuiCol_TabActive] = ImVec4(0.56f, 0.30f, 0.30f, 0.90f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.92f, 0.93f, 0.94f, 0.99f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.91f, 0.74f, 0.74f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.81f, 0.80f, 0.80f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.35f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.61f, 0.48f, 0.48f, 0.78f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.97f, 0.95f, 0.95f, 0.86f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.83f, 0.18f, 0.18f, 0.41f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(0.85f, 0.63f, 0.63f, 0.95f);
		colors[ImGuiCol_NavHighlight] = ImVec4(0.98f, 0.26f, 0.39f, 0.80f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.70f, 0.70f, 0.70f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);


	}
}
