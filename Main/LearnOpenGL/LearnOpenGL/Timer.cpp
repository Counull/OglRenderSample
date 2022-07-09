#include "Timer.h"
#include <iostream>
float Timer::CurrentFrameTime = 0;
float Timer::DeltaTime = 0;
float Timer::LastFrameTime = 0;
void Timer::tick()
{
	CurrentFrameTime = glfwGetTime();
	DeltaTime = CurrentFrameTime - LastFrameTime;
	LastFrameTime = CurrentFrameTime;
//	std::cout << "frame time:" << DeltaTime*1000 << "ms FPS:" << 1 / DeltaTime << std::endl;
}
