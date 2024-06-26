﻿#pragma once

void UpdatePositionPaddle1(Paddle& paddle1)
{
	const float dy = 10.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if (paddle1.GetY() < WINDOW_HEIGHT - PADDLE_HEIGHT)
			paddle1.Judejimas(dy);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if (paddle1.GetY() > 0)
			paddle1.Judejimas(-dy);
}
void UpdatePositionPaddle2(Paddle& paddle2)
{
	const float dy = 10.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (paddle2.GetY() < WINDOW_HEIGHT - PADDLE_HEIGHT)
			paddle2.Judejimas(dy);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (paddle2.GetY() > 0)
			paddle2.Judejimas(-dy);
}
void UpdateMovingObstacles1(moving_Obstacles1& movingObstacles1)
{
	const float dy = 10.0f;
	movingObstacles1.x += movingObstacles1.dx;
	movingObstacles1.y += movingObstacles1.dy;
	if (movingObstacles1.y <= 0)
	{
		movingObstacles1.dy = fabs(movingObstacles1.dy);
	}
	if (movingObstacles1.y >= WINDOW_HEIGHT)
		movingObstacles1.dy = -fabs(movingObstacles1.dy);
}
void UpdateMovingObstacles2(moving_Obstacles2& movingObstacles2)
{
	const float dy = 10.0f;
	movingObstacles2.x += movingObstacles2.dx;
	movingObstacles2.y += movingObstacles2.dy;
	if (movingObstacles2.y <= 0)
	{
		movingObstacles2.dy = fabs(movingObstacles2.dy);
	}
	if (movingObstacles2.y >= WINDOW_HEIGHT)
		movingObstacles2.dy = -fabs(movingObstacles2.dy);
}

bool IsBetween(float val, float rangeB, float rangeE)
{
	return val > rangeB && val < rangeE;
}

template <typename T>
bool IsCollision(Ball& ball, T& obj)
{
	const bool betweenX = IsBetween(ball.GetX(), obj.x, obj.x + PADDLE_WIDTH) ||
		IsBetween(ball.GetX() + BALL_WIDTH, obj.x, obj.x + PADDLE_WIDTH);

	const bool betweenY = IsBetween(ball.GetY(), obj.y, obj.y + PADDLE_HEIGHT) ||
		IsBetween(ball.GetY() + BALL_WIDTH, obj.y, obj.y + PADDLE_HEIGHT);

	return betweenX && betweenY;
}

void UpdatePositionBall(Ball& ball, Paddle& paddle1, Paddle& paddle2, moving_Obstacles1& movingObstacles1, moving_Obstacles2& movingObstacles2, float& score1, float& score2, float& dx, float& dy)
{
	if (ball.GetX() > paddle2.GetX() && paddle2.GetY() - BALL_HEIGHT < ball.GetY() && ball.GetY() < paddle2.GetY() + PADDLE_HEIGHT)
	{
		dx = -dx;
		dy += rand() % 5 - 3;
	}
	if (ball.GetX() < paddle1.GetX() && paddle1.GetY() - BALL_HEIGHT < ball.GetY() && ball.GetY() < paddle1.GetY() + PADDLE_HEIGHT)
	{
		dx = -dx;
		dy += rand() % 5 - 3;
	}

	if (IsCollision(ball, movingObstacles1))
	{
		dx = -dx;
		dy += rand() % 5 - 3;
	}

	if (IsCollision(ball, movingObstacles2))
	{
		dx = -dx;
	}

	ball.Judejimas(dx, dy);

	if (ball.GetY() <= 0)
	{
		dy = fabs(dy);
	}
	if (ball.GetY() >= WINDOW_HEIGHT)
	{
		dy = -fabs(dy);
	}
	if (ball.GetX() > WINDOW_WIDTH)
	{
		dy = 0;
		dx = -dx;
		ball.Reset();
		score1 += 1;
	}
	if (ball.GetX() < -BALL_WIDTH)
	{
		dy = 0;
		dx = -dx;
		ball.Reset();
		score2 += 1;
	}
}
