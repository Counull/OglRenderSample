#include "Application.h"


#include <iostream>
#include "ApplicationEventManager.h"
#include "OpenGLRender.h"
#include "UuidTool.h"

double Application::lastCursorX = 0;
double Application::lastCursorY = 0;
Application::Application() :UUID(UuidTool::random())
{

}

void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	ApplicationEventManager::GetInstance().postWindowSizeChangeEvent(window, width, height);
}


void Application::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	ApplicationEventManager::GetInstance().postMouseEvent(window, xpos, ypos);
	lastCursorX = xpos;
	lastCursorY = ypos;
	std::cout << "callback" << std::endl; ;
}

void Application::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	ApplicationEventManager::GetInstance().postScrollEvent(window, xoffset, yoffset);
}

void Application::onKeyboardAction(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

int Application::start()
{


	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(Config::ScreenWidth, Config::ScreenHeight, "LearnOpenGL", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);//隐藏光标
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	ApplicationEventManager::GetInstance().registerKeyboardCallback(UUID, this);
	std::unique_ptr	<Render> render ( new OpenGLRender());
	render->onInit();
	glfwGetCursorPos(window, &lastCursorX, &lastCursorY);
	glfwSetCursorPosCallback(window, mouse_callback);//设置光标回调
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	Timer::LastFrameTime = glfwGetTime();
	while (!glfwWindowShouldClose(window))
	{
		Timer::tick();

		ApplicationEventManager::GetInstance().postKeyboardEvent(window);
		ApplicationEventManager::GetInstance().postOnTick();
		render->onDraw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	render->onDestory();
	glfwTerminate();

	return 0;
}


