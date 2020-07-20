#pragma once

#include "gui_layer.h"
namespace fv {
	class Main_Menu : public Layer
	{
		public:
		Main_Menu() { this->name = "Main Menu"; };
		void RenderGui();
		~Main_Menu() = default;
	};
}