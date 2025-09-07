#pragma once 

#include <string>
#include <utility>

namespace fv {
	class Layer
	{
	public:

		explicit Layer(std::string name = "Layer") : name{std::move( name )} {};
		virtual ~Layer() = default;
		virtual void RenderGui() {}
		[[nodiscard]] const std::string& GetName() const { return name; }
	protected:
		std::string name;
	};
}