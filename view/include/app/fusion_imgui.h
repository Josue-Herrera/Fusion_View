#pragma once

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <misc/freetype/imgui_freetype.h>

namespace fv {
	class Fusion_Imgui {
	public:
		Fusion_Imgui();
		~Fusion_Imgui();
		void start();
		static void end();
		void showDemo();
		bool shutdown();
		void ForceShutdown() const { glfwSetWindowShouldClose(fv_window, GLFW_TRUE); };
	private:
		GLFWwindow* fv_window{};
	};
}

