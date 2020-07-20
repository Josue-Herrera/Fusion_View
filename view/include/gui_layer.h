#pragma once 

#include <string>

namespace fv {
	class Layer
	{
	public:

		Layer(const std::string& name = "Layer") : name{ name } {};
		virtual ~Layer() = default;

		virtual void RenderGui() {}

		const std::string& GetName() const { return name; }
	protected:
		std::string name;
	};
}