#include "..\include\main_menu.h"
#include "imgui.h"
#include "imgui_helper.h"
#include <cmrc/cmrc.hpp>

CMRC_DECLARE(fv);

void fv::Main_Menu::RenderGui()
{	
	msw_window_view();
}

constexpr float initial_width = 800;
constexpr float initial_height= 600;

enum class pos {LEFT, RIGHT, CENTER};

void Layout_Parent(pos dir, ImVec2 FixedSizedObject) {
	auto io = ImGui::GetIO();
	auto [w, h] = io.DisplaySize;

	switch (dir) {
	case pos::LEFT:
		ImGui::SetNextWindowPos(ImVec2(0, 0)); break;
	case pos::CENTER:
		ImGui::SetNextWindowPos(ImVec2((w / 2) - (FixedSizedObject.x / 2), (h / 2) - (FixedSizedObject.y / 2))); break;
	case pos::RIGHT:
		ImGui::SetNextWindowPos(ImVec2(w - FixedSizedObject.x, 0)); break;
	default:
		ImGui::SetNextWindowPos(ImVec2(0, 0));
	}
	
	ImGui::SetNextWindowSize(FixedSizedObject);
}

void Layout_Item(pos dir, ImVec2 FixedSizedObject) {

	auto [w,h] = ImGui::GetWindowSize();

	switch (dir) {
	case pos::LEFT:
			break;
	case pos::CENTER:
		ImGui::Dummy(ImVec2(FixedSizedObject.x / 2, 0)); ImGui::SameLine(); break;
	case pos::RIGHT:
		
		ImGui::Dummy(ImVec2(w - FixedSizedObject.x, 0)); ImGui::SameLine(); break;
	default:
		ImGui::Dummy(ImVec2(0, 0)); ImGui::SameLine();
	}
}

bool fv::Main_Menu::msw_window_view()
{
	ImGuiWindowFlags msw_flags2 = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar
		| ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;

	float width, height;
	width = initial_width;
	height = initial_height;
	ImVec2 test(0, 0);

	Layout_Parent(pos::CENTER, ImVec2(200,200));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.73f, 0.51f, 0.51f, 1.0f));


	ImGui::Begin("test",(bool*)true,msw_flags2);

	Layout_Item(pos::CENTER, test);
	ImGui::Text("Center? TOP LEFT!");
	test = ImGui::GetItemRectSize();

	ImGui::End();
	ImGui::PopStyleColor();

	return true;
}



