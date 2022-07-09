#include "ApplicationEventManager.h"
#include <iostream>
ApplicationEventManager& ApplicationEventManager::GetInstance()
{
	static ApplicationEventManager Instance;
	return Instance;
}

void ApplicationEventManager::registerKeyboardCallback(const std::string & UUID, KeyBoradCallBack* callback)
{
	keybordCallbackMap.insert(std::make_pair(UUID, callback));

}

void ApplicationEventManager::registerMouseCallback(const std::string& UUID, MouseCallback* callback)
{
	mouseCallbackMap.insert(std::make_pair(UUID, callback));
}

void ApplicationEventManager::registerScrollCallback(const std::string& UUID, ScrollCallback* callback)
{
	scrollCallbackMap.insert(std::make_pair(UUID, callback));
}

void ApplicationEventManager::registerWindowSizeCallback(const std::string& UUID, WindowSizeChangeCallBack* callback)
{
	windowSizeCallbackMap.insert(std::make_pair(UUID, callback));
}

void ApplicationEventManager::registerGameComponent(const std::string& UUID, GameComponent* component)
{
	gameComponentMap.insert(std::make_pair(UUID, component));
}

ApplicationEventManager::ApplicationEventManager()
{
}

void ApplicationEventManager::postKeyboardEvent(GLFWwindow* window)
{
	for (auto kv : keybordCallbackMap) {
		kv.second->onKeyboardAction(window);
	}
}

void ApplicationEventManager::postMouseEvent(GLFWwindow* window, double xpos, double ypos)
{
	for (auto kv : mouseCallbackMap) {
		kv.second->onMouseMove(window, xpos, ypos);
	}

}

void ApplicationEventManager::postScrollEvent(GLFWwindow* window, double xoffset, double yoffset)
{
	for (auto kv: scrollCallbackMap) {
		kv.second->onMouseScroll(window, xoffset, yoffset);
	}
}

void ApplicationEventManager::postWindowSizeChangeEvent(GLFWwindow* window, int width, int height)
{
	for (auto kv : windowSizeCallbackMap) {
		kv.second->onWindowSizeChange(window, width, height);
	}
}

void ApplicationEventManager::postOnTick()
{
	for (auto kv : gameComponentMap) {
		kv.second->onTick() ;
	}
}
