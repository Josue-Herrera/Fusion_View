#include "panels/main_menu.h"

#include <imgui.h>
#include <cmrc/cmrc.hpp>

CMRC_DECLARE(fv);

void fv::Main_Menu::RenderGui()
{
	msw_window_view();
}

constexpr float initial_width = 800;
constexpr float initial_height = 600;

enum class pos { LEFT, RIGHT, CENTER };

static void layout_parent(const pos dir, const ImVec2& fixed_size)
{
	auto io = ImGui::GetIO();
	auto [w, h] = io.DisplaySize;

	switch (dir) {
	case pos::LEFT:   ImGui::SetNextWindowPos(ImVec2(0, 0)); break;
	case pos::CENTER: ImGui::SetNextWindowPos(ImVec2((w / 2) - (fixed_size.x / 2), (h / 2) - (fixed_size.y / 2))); break;
	case pos::RIGHT:  ImGui::SetNextWindowPos(ImVec2(w - fixed_size.x, 0)); break;
	default:          ImGui::SetNextWindowPos(ImVec2(0, 0));
	}

	ImGui::SetNextWindowSize(fixed_size);
}

static void layout_item(const pos dir, const ImVec2& fixed_size)
{
	auto [w, h] = ImGui::GetWindowSize();
	(void)h;
	switch (dir) {
	case pos::LEFT:   break;
	case pos::CENTER: ImGui::Dummy(ImVec2(fixed_size.x / 2, 0)); ImGui::SameLine(); break;
	case pos::RIGHT:  ImGui::Dummy(ImVec2(w - fixed_size.x, 0)); ImGui::SameLine(); break;
	default:          ImGui::Dummy(ImVec2(0, 0)); ImGui::SameLine();
	}
}

bool fv::Main_Menu::msw_window_view()
{
	constexpr ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar
		| ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;

	layout_parent(pos::CENTER, ImVec2(200, 200));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.73f, 0.51f, 0.51f, 1.0f));

	bool open = true;
	ImGui::Begin("main_menu", &open, flags);

	layout_item(pos::CENTER, ImVec2(0, 0));
	ImGui::Text("Center? TOP LEFT!");

	ImGui::End();
	ImGui::PopStyleColor();

	return true;
}

