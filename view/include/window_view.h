#pragma once 

#ifdef WIN32
#include <Windows.h>
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace fv {

	class window_view {

	public:
		static window_view& get_window_view() {
			static window_view instance;
			return instance;
		}
		
		~window_view();
		void setVsync(const bool val);
		void initGLFW();
		void createWindow();
		void onUpdate();
		GLFWwindow* get_ptr() { return fv_window;  }
		int width, height;
	private:
		void framebuffer_size_callback(GLFWwindow* window, const int width, const int height);
		const int fv_width = 1280;
		const int fv_height = 860;
		GLFWwindow* fv_window;
		const char* title = "Fusion View";
		bool Vsync;
	};
}