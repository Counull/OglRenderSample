#pragma once
#include <GLFW/glfw3.h>
class KeyBoradCallBack
{
public:
	virtual void  onKeyboardAction(GLFWwindow* window)=0;
};
class MouseCallback
{
public:
	virtual void onMouseMove(GLFWwindow* window, double xpos, double ypos) = 0;
};

class ScrollCallback {
public:
	virtual void onMouseScroll(GLFWwindow* window, double xoffset, double yoffset) = 0;
};

class WindowSizeChangeCallBack {
public:
	virtual void onWindowSizeChange(GLFWwindow* window, int width, int height) = 0;
};

class GameComponent {
public:
	virtual void  onTick() = 0;
};