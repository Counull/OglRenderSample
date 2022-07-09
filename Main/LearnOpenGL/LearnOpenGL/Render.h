#pragma once
class Render
{
public:
	virtual void  onInit() = 0;
	virtual void onDraw() = 0;
	virtual void onDestory() = 0;
	virtual ~Render()=default;
};

