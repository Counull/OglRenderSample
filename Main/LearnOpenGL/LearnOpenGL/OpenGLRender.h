#pragma once
#include "Render.h"
#include "Shader.h"
#include "Camera.h"
#include "Config.h"
#include "Timer.h"
#include "ApplicationCallBack.h"
#include "Model.h"
class OpenGLRender :public Render, public KeyBoradCallBack, public ScrollCallback, public MouseCallback, public WindowSizeChangeCallBack
{

public:
	OpenGLRender();
	void onInit();
	void onDraw();
	void onDestory();
	void  onKeyboardAction(GLFWwindow* window);
	void onMouseMove(GLFWwindow* window, double xpos, double ypos);
	void onMouseScroll(GLFWwindow* window, double xoffset, double yoffset);
	void onWindowSizeChange(GLFWwindow* window, int width, int height);

	void initLight();
private:

	Model model;
	std::string UUID;
	glm::mat4 projection = glm::mat4(1.0f);
	Camera camera;
	Shader shader;
	Shader lightShader;
	glm::vec3 lightPos;
	unsigned int VAO, VBO, EBO, lightVAO;
	unsigned int texture[2];

	float texCoords[6] = {
	0.0f, 0.0f, // 左下角
	1.0f, 0.0f, // 右下角
	0.5f, 1.0f // 上中
	};

	unsigned int indices[6] = { // 注意索引从0开始! 
		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形
	};

	float* pVertices;

	glm::vec3 cubePositions[10] = {
	  glm::vec3(0.0f,  0.0f,  0.0f),
	  glm::vec3(2.0f,  5.0f, -15.0f),
	  glm::vec3(-1.5f, -2.2f, -2.5f),
	  glm::vec3(-3.8f, -2.0f, -12.3f),
	  glm::vec3(2.4f, -0.4f, -3.5f),
	  glm::vec3(-1.7f,  3.0f, -7.5f),
	  glm::vec3(1.3f, -2.0f, -2.5f),
	  glm::vec3(1.5f,  2.0f, -2.5f),
	  glm::vec3(1.5f,  0.2f, -1.5f),
	  glm::vec3(-1.3f,  1.0f, -1.5f)
	};



};

