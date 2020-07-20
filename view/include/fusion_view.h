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
		void loadComponents();
		Fusion_Imgui* imgui;
		Gui_Stack gui_stack;
	};

	
}