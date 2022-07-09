#pragma once
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include "Render.h"
#include "ApplicationCallBack.h"
#include <string>
#include <memory>

class Application :public KeyBoradCallBack
{
	static	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void  onKeyboardAction(GLFWwindow* window);
	
	const std::string UUID;

	
public:
	static double lastCursorX, lastCursorY;
	Application();
	int start();

};

