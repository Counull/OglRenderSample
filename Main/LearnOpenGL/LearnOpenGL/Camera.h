#pragma once
#include <glm/glm.hpp>
//很显然写好一个Camera并不容易硬重构分开各部分属性值
class Camera
{
public:

	Camera();

	enum Direction
	{
		Front = 0,
		Back = 1,
		Left = 2,
		Right = 3
	};

	glm::mat4 view;
	float speed = 5.0f;

	void hoverHorizontal(const float& radius, const glm::vec3& point);

	void setPos(const glm::vec3& newPos);
	void setTarget(const glm::vec3& newTarget);
	void setFront(const glm::vec3& newFront);

	void setYawPitch(float newYaw, float newPitch);

	float getYaw();
	float getPitch();
	glm::vec3 getPos() const;
	glm::vec3 getFront() const;

	void move(Direction direction);
	float fov;


private:


	glm::vec3 pos;
	glm::vec3 target;
	glm::vec3 up;
	glm::vec3 direction;
	glm::vec3 right;
	glm::vec3 front;


	
	float pitch;
	float yaw;
	inline void refreshCamera();

};

