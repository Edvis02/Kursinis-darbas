#pragma once
#include "Defines.h"

class Ball
{
private:
	float x, y;
public:
	Ball() : x(MID_X), y(MID_Y) {}
	Ball(float _x, float _y) : x(_x), y(_y) {}
	~Ball() {}
	int GetX();
	int GetY();
	void Judejimas(int movementX, int movementY);
	void Reset();
};

class Paddle
{
private:
	float x, y;
public:
	Paddle(float x1, float y1) : x(x1), y(y1) {}
	~Paddle() {}
	int GetX();
	int GetY();
	void Judejimas(int movementY);
};
struct moving_Obstacles1
{
	float x, y, dx, dy;
};
struct moving_Obstacles2
{
	float x, y, dx, dy;
};