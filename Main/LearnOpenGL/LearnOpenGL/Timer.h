#pragma once
#include <GLFW/glfw3.h>
class Timer
{

public :
static	float DeltaTime; // ��ǰ֡����һ֡��ʱ���
static float LastFrameTime ; // ��һ֡��ʱ��
static	float CurrentFrameTime ;

static void tick();

};

