#pragma once

#include "gui_layer.h"
#include "imgui_helper.h"

namespace fv {
	struct msw_window_size {
		float width;
		float height;
	};

	class Main_Menu : public Layer
	{
		public:
		Main_Menu(bool * close): close(close) { 
			this->name = "Main Menu"; 

			LoadTextureFromFile("..\\..\\resources\\2x\\baseline_settings_black_18dp.png", &texture, &w, &h);

		};
		void RenderGui();
		~Main_Menu() = default;

	private:

		int w = 0, h = 0;
		unsigned int texture;

		bool * close;
		bool main_side_open;
		int msw_starting_height;
		msw_window_size msw_size;
		bool msw_window_view();
		void msw_set_window_size();
		void header_bar();
	};
}