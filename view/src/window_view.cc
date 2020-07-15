#include <iostream>
#include "..\include\window_view.h"

namespace fv {
	
	void glfw_error_callback(int error, const char* description)
	{
		fprintf(stderr, "Glfw Error %d: %s\n", error, description);
	}

	void window_view::framebuffer_size_callback(GLFWwindow* window,const int in_width, const int in_height)
	{
		width = in_width;
		height = in_height;
		glViewport(0, 0, in_width, in_height);
	}
	window_view::~window_view()
	{
		glfwDestroyWindow(fv_window);
		glfwTerminate();
	}

	void window_view::setVsync(const bool val)
	{
		if (val)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		Vsync = val;
	}

	void window_view::initGLFW()
	{
		glfwSetErrorCallback(glfw_error_callback);

		if (glfwInit()) {
			std::cout << " Failed to init GLFW " << std::endl;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void window_view::createWindow()
	{	

#ifdef WIN32
		::ShowWindow(::GetConsoleWindow(), SW_HIDE);
#endif 
		
		if (fv_window = glfwCreateWindow(fv_width, fv_height, title, NULL, NULL); fv_window == NULL)
		{
			std::cout << "fv::window_view::createWindow() Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}

		gladLoadGL();
	}
	void window_view::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(fv_window);
	}
}