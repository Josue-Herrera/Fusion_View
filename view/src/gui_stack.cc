#include "gui_stack.h"

namespace fv {

	Gui_Stack::~Gui_Stack()
	{
		for (Layer* layer : gui_layers)
		{
			delete layer;
		}
	}

	void Gui_Stack::PushGui(Layer* layer)
	{
		gui_layers.emplace(gui_layers.begin() + gui_LayerInsertIndex, layer);
		gui_LayerInsertIndex++;
	}

	void Gui_Stack::PopGui(Layer* layer)
	{
		auto it = std::find(gui_layers.begin(), gui_layers.begin() + gui_LayerInsertIndex, layer);
		if (it != gui_layers.begin() + gui_LayerInsertIndex)
		{
			{
				gui_layers.erase(it);
				gui_LayerInsertIndex--;
			}
		}
	}
}