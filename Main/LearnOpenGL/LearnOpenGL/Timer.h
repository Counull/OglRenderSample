#pragma once
#include <GLFW/glfw3.h>
class Timer
{

public :
static	float DeltaTime; // 当前帧与上一帧的时间差
static float LastFrameTime ; // 上一帧的时间
static	float CurrentFrameTime ;

static void tick();

};

