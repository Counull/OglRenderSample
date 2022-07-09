#pragma once

#ifndef SHADER_H

#define SHADER_H

#include <glad/glad.h>
// ����glad����ȡ���еı���OpenGLͷ�ļ�

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Shader
{
public:
	unsigned int ID = 0;

	// ��������ȡ��������ɫ��

	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	// ʹ��/�������
	void use() const;
	// uniform���ߺ���
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMatrix4 (const std::string& name, const glm::mat4& trans) const;
	void setVec3(const std::string& name, float x, float y, float z)const;
	void setVec3(const std::string& name, const glm::vec3& vec3)const;
};



#endif