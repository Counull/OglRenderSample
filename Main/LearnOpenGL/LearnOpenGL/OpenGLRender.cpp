#include "OpenGLRender.h"
#include "stb_image.h"
#include"UuidTool.h"
#include"ApplicationEventManager.h"
#include "Application.h"
#include <memory_resource>
#include <vector>
#include "Model.h"


OpenGLRender::OpenGLRender() :UUID(UuidTool::random()),
shader(Shader("shader\\vertext.vert", "shader\\fragement.frag")),
lightShader("shader\\vertext.vert", "shader\\light.frag"),
lightPos(1.2f, 1.0f, 2.0f)
{


	model = std::pmr::vector<float>{
		// positions          // normals           // texture coords
	  -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
	   0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
	   0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	   0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	  -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
	  -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

	  -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
	   0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
	   0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	   0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	  -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
	  -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

	  -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	  -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	  -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	  -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	  -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	  -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	   0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	   0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	   0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	   0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	   0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	   0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	  -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
	   0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
	   0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	   0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	  -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
	  -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

	  -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
	   0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
	   0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	   0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	  -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
	  -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	std::cout << sizeof(pVertices) << std::endl;

}

void OpenGLRender::onInit()
{


	ApplicationEventManager::GetInstance().registerKeyboardCallback(UUID, this);
	ApplicationEventManager::GetInstance().registerScrollCallback(UUID, this);
	ApplicationEventManager::GetInstance().registerMouseCallback(UUID, this);
	ApplicationEventManager::GetInstance().registerWindowSizeCallback(UUID, this);
	glViewport(0, 0, Config::ScreenWidth, Config::ScreenHeight);
	//查询着色器顶点属性数量
	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

	//顶点数组对象(Vertex Array Object, VAO)
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	//顶点缓冲 顶点缓冲对象：Vertex Buffer Object，VBO
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, model.vert.size() * sizeof(float), &model.vert[0], GL_STATIC_DRAW);



	//索引缓冲对象(Element Buffer Object，EBO，也叫Index Buffer Object，IBO)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	initLight();


	//添加纹理参数
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true); //垂直翻转
	int width, height, nrChannels;



	unsigned char* data = stbi_load("texture\\container2.png", &width, &height, &nrChannels, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	glGenTextures(1, &texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[1]);

	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	// data = stbi_load("texture\\awesomeface.png", &width, &height, &nrChannels, 0);
	data = stbi_load("texture\\container2_specular.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		//如果是png格式的纹理应用GL_RGBA格式解析
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	//glUseProgram(shader.ID);




	glEnable(GL_DEPTH_TEST);
	/*glUniform1i(glGetUniformLocation(shader.ID, "texture1"),0);
	glUniform1i(glGetUniformLocation(shader.ID, "texture2"),1);*/

	//变换矩阵
}

void OpenGLRender::onDraw()
{

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//	glm::mat4 model = glm::mat4(1.0f);;
		//	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
		//model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

	//camera.hoverHorizontal(10, glm::vec3(1.0f, 1.0f, 0.0f));
	shader.use();
	shader.setInt("texture1", 0);
	shader.setInt("texture2", 1);
	shader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
	shader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);

	shader.setVec3("viewPos", camera.getPos());




	



	shader.setVec3("light.position", lightPos);
	shader.setVec3("light.ambient", 0.5f, 0.5f, 0.5f);
	shader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);

	shader.setVec3("material.ambient", 1.0f, 0.5f, 0.31f);
	shader.setInt("material.diffuse", 0);
	shader.setInt("material.specular", 1);
	shader.setFloat("material.shininess", 32.0f);


	shader.setMatrix4("view", camera.view);
	projection = glm::perspective(glm::radians(camera.fov), Config::Aspect, 0.1f, 100.0f);
	shader.setMatrix4("projection", projection);



	//line = !line;

	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glm::mat4 model = glm::mat4(1.0f);
	float angle = 20.0f;
	model = glm::rotate(model, Timer::CurrentFrameTime * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
	shader.setMatrix4("model", model);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	lightShader.use();
	lightShader.setMatrix4("projection", projection);
	lightShader.setMatrix4("view", camera.view);
	model = glm::mat4(1.0f);
	model = glm::translate(model, lightPos);
	model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
	lightShader.setMatrix4("model", model);

	glBindVertexArray(lightVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void OpenGLRender::onDestory()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shader.ID);
}

void OpenGLRender::onKeyboardAction(GLFWwindow* window)
{

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		camera.move(Camera::Front);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		camera.move(Camera::Back);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		camera.move(Camera::Left);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)

	{
		camera.move(Camera::Right);
	}
}

void OpenGLRender::onMouseMove(GLFWwindow* window, double xpos, double ypos)
{


	float xOffset = xpos - Application::lastCursorX;
	float yOffset = Application::lastCursorY - ypos;


	xOffset *= Config::sensitivity;
	yOffset *= Config::sensitivity;

	float cameraYaw = camera.getYaw() + xOffset;
	float cameraPitch = camera.getPitch() + yOffset;

	if (cameraPitch > 89.0f)
		cameraPitch = 89.0f;
	if (cameraPitch < -89.0f)
		cameraPitch = -89.0f;

	if (cameraYaw > 180) { //限制度数为正负180度
		cameraYaw = cameraYaw - 360.0f;
	}
	else if (cameraYaw < -180)
	{
		cameraYaw = cameraYaw + 360.0f;
	}
	camera.setYawPitch(cameraYaw, cameraPitch);
}

void OpenGLRender::onMouseScroll(GLFWwindow* window, double xoffset, double yoffset)
{
	if (camera.fov >= 1.0f && camera.fov <= 45.0f)
		camera.fov -= yoffset;
	if (camera.fov <= 1.0f)
		camera.fov = 1.0f;
	if (camera.fov >= 45.0f)
		camera.fov = 45.0f;
}

void OpenGLRender::onWindowSizeChange(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void OpenGLRender::initLight()
{
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

}
