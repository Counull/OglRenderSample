#include "Camera.h"
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_transform.hpp>
#include <iostream>
#include "Timer.h"
Camera::Camera() :
	pos(glm::vec3(0.0f, 0.0f, 3.0f)), target(glm::vec3(0.0f, 0.0f, 0.0f)), front(glm::normalize(target - pos)),
	yaw(-90.0f), pitch(0.0f),fov(45.0f)
{
	refreshCamera();

}

void Camera::hoverHorizontal(const float& radius, const glm::vec3& point)
{

	float camX = sin(glfwGetTime()) * radius + point.x;
	float camZ = cos(glfwGetTime()) * radius + point.z;
	pos = glm::vec3(camX, point.y, camZ);
	view = glm::lookAt(pos, point, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::setPos(const glm::vec3& newPos)
{
	pos = newPos;
	refreshCamera();
}

void Camera::setTarget(const glm::vec3& newTarget)
{

	target = newTarget;
	front = glm::normalize(target - pos);
	refreshCamera();
}

void Camera::setFront(const glm::vec3& newFront)
{
	front = glm::normalize(newFront);
	target = pos + front;
	refreshCamera();
}

void Camera::setYawPitch(float newYaw, float newPitch)
{
	yaw = newYaw;
	pitch = newPitch;
	float x =  cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	float y =  sin(glm::radians(pitch));
	float z =  cos(glm::radians(pitch)) * sin(glm::radians(yaw));

	setFront(glm::normalize(glm::vec3(x, y, z)));
}

float Camera::getYaw()
{
	return yaw;
}

float Camera::getPitch()
{
	return pitch;
}

glm::vec3 Camera::getPos() const
{
	return pos;
}

glm::vec3 Camera::getFront() const
{
	return front;
}

void Camera::move(Direction direction)
{


	switch (direction)
	{
	case Front:
		pos += front * speed * Timer::DeltaTime;
		break;

	case Back:
		pos -= front * speed * Timer::DeltaTime;
		break;

	case Left:
		pos -= glm::normalize(glm::cross(front, up)) * speed * Timer::DeltaTime;
		break;
	case Right:
		pos += glm::normalize(glm::cross(front, up)) * speed * Timer::DeltaTime;
		break;
	default:
		break;
	}
	target = pos + front;
	view = glm::lookAt(pos, target, up);
}



inline void Camera::refreshCamera()
{
	glm::vec3 u = glm::vec3(0.0f, 1.0f, 0.0f);
	direction = glm::normalize(pos - target);
	right = glm::normalize(glm::cross(u, direction));
	up = glm::cross(direction, right);
	view = glm::lookAt(pos, target, up);
}



