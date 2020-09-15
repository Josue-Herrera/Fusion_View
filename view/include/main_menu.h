#pragma once

#include "gui_layer.h"

namespace fv {
	struct msw_window_size {
		float width;
		float height;
	};

	class Main_Menu : public Layer
	{
		public:
		Main_Menu() { 
			this->name = "Main Menu"; 
		};
		void RenderGui();
		~Main_Menu() = default;

	private:
		 
		bool main_side_open;
		int msw_starting_height;
		msw_window_size msw_size;
		bool msw_window_view();
		void msw_set_window_size();
		void header_bar();
	};
}