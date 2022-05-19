#include "Objects.h"
#include <iostream>

int Ball::GetX()
{
	return x;
}
int Ball::GetY()
{
	return y;
}
void Ball::Judejimas(int movementX, int movementY)
{
	x += movementX;
	y += movementY;
}
void Ball::Reset()
{
	x = MID_X;
	y = MID_Y;
}
int Paddle::GetX()
{
	return x;
}
int Paddle::GetY()
{
	return y;
}
void Paddle::Judejimas(int movementY)
{
	y += movementY;
}