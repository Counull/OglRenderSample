#pragma once
#include <unordered_map>
#include <string>
#include "ApplicationCallback.h"

//���ǲ���Ӧ��д��ģ��������ظ�дһģһ���Ĵ���ü��Σ�����
class ApplicationEventManager
{

public:
	static ApplicationEventManager& GetInstance();
	friend class Application;
	

	void registerKeyboardCallback(const std::string & UUID, KeyBoradCallBack* callback);
	void registerMouseCallback(const std::string& UUID, MouseCallback* callback);
	void registerScrollCallback(const std::string& UUID, ScrollCallback* callback);
	void registerWindowSizeCallback(const std::string& UUID, WindowSizeChangeCallBack* callback);
	void registerGameComponent(const std::string& UUID, GameComponent* Component);


private:
	ApplicationEventManager(const ApplicationEventManager&)=delete; //���ÿ�������
	ApplicationEventManager& operator = (const ApplicationEventManager&)=delete;//���ÿ�������
	ApplicationEventManager();

	void postKeyboardEvent(GLFWwindow* window);
	void postMouseEvent(GLFWwindow* window, double xpos, double ypos);
	void postScrollEvent(GLFWwindow* window, double xoffset, double yoffset);
	void postWindowSizeChangeEvent(GLFWwindow* window, int width, int height);
	void postOnTick();

	std::unordered_map<std::string, KeyBoradCallBack*> keybordCallbackMap;
	std::unordered_map<std::string, MouseCallback*> mouseCallbackMap;
	std::unordered_map<std::string, ScrollCallback*> scrollCallbackMap;
	std::unordered_map<std::string, WindowSizeChangeCallBack*> windowSizeCallbackMap;
	std::unordered_map<std::string, GameComponent*> gameComponentMap;

};

