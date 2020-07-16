#pragma once

#include "fusion_imgui.h"

namespace fv {
	class Fusion_View
	{

	public:
		Fusion_View();
		~Fusion_View();
		void run();
	private:
		Fusion_Imgui* imgui;

	};

	
}