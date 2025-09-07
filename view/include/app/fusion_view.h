#pragma once

#include "app/fusion_imgui.h"
#include "panels/gui_stack.h"
#include "app/app_context.h"

namespace fv {
	class Fusion_View
	{
	public:
		Fusion_View();
		~Fusion_View();
		void run();
	private:
		ImFont* label_font{};
		void loadComponents();
		static void loadDarkStyle();
		Fusion_Imgui* imgui;
		Gui_Stack gui_stack;
		bool should_close = false;
		app_context ctx_{};
	};
}
