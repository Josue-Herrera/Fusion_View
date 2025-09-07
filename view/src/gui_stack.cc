#include "gui_stack.h"
#include <algorithm>
namespace fv {

	Gui_Stack::~Gui_Stack()
	{
		for (const Layer* layer : gui_layers)
		{
			delete layer;
		}
	}

	void Gui_Stack::PushGui(Layer* layer)
	{
		gui_layers.emplace(gui_layers.begin() + gui_LayerInsertIndex, layer);
		gui_LayerInsertIndex++;
	}

	void Gui_Stack::PopGui(const Layer* layer)
	{
		if (const auto it = std::find(gui_layers.begin(), gui_layers.begin() + gui_LayerInsertIndex, layer);
			it != gui_layers.begin() + gui_LayerInsertIndex)
		{
			{
				gui_layers.erase(it);
				gui_LayerInsertIndex--;
			}
		}
	}
}