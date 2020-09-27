#include "..\include\main_menu.h"
#include "imgui.h"
#include "imgui_helper.h"
#include <cmrc/cmrc.hpp>

CMRC_DECLARE(fv);

void fv::Main_Menu::RenderGui()
{	
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.19f, 0.18f, 0.18f, 1.00f));
	header_bar();
	msw_window_view();
	ImGui::PopStyleColor();
}

void fv::Main_Menu::header_bar()
{
	auto io = ImGui::GetIO();
	float max_width = io.DisplaySize.x;
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(max_width, 21));
	
	ImGuiWindowFlags hb_flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar
		| ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBringToFrontOnFocus;

	ImGui::Begin("Header_Bar", (bool*)true , hb_flags);

	ImGui::TextDisabled(" Fusion ");

	ImGui::SameLine(max_width - 63.0f);
	if (ImGui::Button("CLOSE")) {
		*close = true;
	}

	ImGui::End();
}

bool fv::Main_Menu::msw_window_view()
{
	msw_set_window_size();
	
	
	ImGuiWindowFlags msw_flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar 
								| ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | 
								ImGuiWindowFlags_NoBringToFrontOnFocus;
	

	auto fs = cmrc::fv::get_filesystem();
	auto font = fs.open("google/home/3x/baseline_home_white_18dp.png");
 
	LoadTextureFromMemory((unsigned char*)font.begin(), font.size(), &texture, &w, &h);

	ImGui::Begin("MainSideWindow##1", &main_side_open, msw_flags);
	ImGui::NewLine();
	ImGui::NewLine();
	ImGui::NewLine();
	//ImGui::Image((void*)(intptr_t)texture, ImVec2((float)w*10, (float)h*10));
	ImGui::TextDisabled("Fusion View");
	ImGui::Text("WOW\n What i wish i was doing with all the skills and Summary\n Monte Corlos");
	ImGui::End();

	return true;
}

void fv::Main_Menu::msw_set_window_size()
{

	auto io = ImGui::GetIO();
	float max_height = io.DisplaySize.y;
	ImGui::SetNextWindowPos(ImVec2(0, 21));
	ImGui::SetNextWindowSize(ImVec2(500, max_height));

}


