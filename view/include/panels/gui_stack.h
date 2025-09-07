#pragma once

#include "panels/gui_layer.h"
#include <vector>

namespace fv {
	class Gui_Stack
	{
	public:
		Gui_Stack() = default;
		~Gui_Stack();

		void PushGui(Layer* layer);
		void PopGui(const Layer* layer);

		std::vector<Layer*>::iterator begin() { return gui_layers.begin(); }
		std::vector<Layer*>::iterator end() { return gui_layers.end(); }
		std::vector<Layer*>::reverse_iterator rbegin() { return gui_layers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return gui_layers.rend(); }

		std::vector<Layer*>::const_iterator begin() const { return gui_layers.begin(); }
		std::vector<Layer*>::const_iterator end() const { return gui_layers.end(); }
		std::vector<Layer*>::const_reverse_iterator rbegin() const { return gui_layers.rbegin(); }
		std::vector<Layer*>::const_reverse_iterator rend() const { return gui_layers.rend(); }
	private:
		std::vector<Layer*> gui_layers;
		unsigned int gui_LayerInsertIndex = 0;
	};
}

