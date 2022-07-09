#pragma once
class Timer
{
public:
	static void tick();
	float deltaTime = 0.0f; // 当前帧与上一帧的时间差
	float lastFrame = 0.0f; // 上一帧的时间

private:

};

