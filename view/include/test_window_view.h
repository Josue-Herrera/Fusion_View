#pragma once

#include "gui_layer.h"
namespace fv {
	class test_window : public Layer
	{
	public:
		test_window() { this->name = "test_window"; };
		void RenderGui();
		~test_window() = default;
	};
}