#pragma once 

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace fv {
	class Fusion_Imgui {
	public:
		Fusion_Imgui();
		~Fusion_Imgui();
		void start() const;
		static void end();
		void showDemo();
		bool shutdown() const;
		void ForceShutdown() const { glfwSetWindowShouldClose(fv_window, GLFW_TRUE); };
	private:
		bool show_demo_window = true;
		bool show_another_window = false;
		GLFWwindow* fv_window;
	};
}
