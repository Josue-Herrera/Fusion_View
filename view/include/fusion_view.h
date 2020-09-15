#pragma once

#include "fusion_imgui.h"
#include "gui_stack.h"

namespace fv {
	class Fusion_View
	{
		
	public:
		Fusion_View();
		~Fusion_View();
		void run();
	private:
		ImFont* label_font;
		void loadComponents();
		void loadDarkStyle();
		Fusion_Imgui* imgui;
		Gui_Stack gui_stack;
		bool should_close = false;
	};

	
}