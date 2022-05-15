#pragma once

void UpdatePositionPaddle1(Paddle1& paddle1)
{
	const float dy = 10.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if (paddle1.y < WINDOW_HEIGHT - PADDLE_HEIGHT)
			paddle1.y += dy;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if (paddle1.y > 0)
			paddle1.y -= dy;
}
void UpdatePositionPaddle2(Paddle2& paddle2)
{
	const float dy = 10.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (paddle2.y < WINDOW_HEIGHT - PADDLE_HEIGHT)
			paddle2.y += dy;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (paddle2.y > 0)
			paddle2.y -= dy;
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
void UpdatePositionBall(Ball& ball, Paddle1& paddle1, Paddle2& paddle2, moving_Obstacles1& movingObstacles1, moving_Obstacles2& movingObstacles2, float& score1, float& score2)
{
	ball.x += ball.dx;
	ball.y += ball.dy;

	if (ball.x > paddle2.x && paddle2.y - BALL_HEIGHT < ball.y && ball.y < paddle2.y + PADDLE_HEIGHT)
	{
		ball.dx = -ball.dx;
		ball.dy += rand() % 5 - 3;
	}
	if (ball.x < paddle1.x && paddle1.y - BALL_HEIGHT < ball.y && ball.y < paddle1.y + PADDLE_HEIGHT)
	{
		ball.dx = -ball.dx;
		ball.dy += rand() % 5 - 3;
	}


	// cia reikia sutvarkyti kazkaip (tvarkymas tarp //)
	if (ball.x > movingObstacles1.x && movingObstacles1.y /*- BALL_HEIGHT*/ < ball.y && ball.y < movingObstacles1.y + PADDLE_HEIGHT)
	{
		ball.dx = -ball.dx;
		ball.dy += rand() % 5 - 3;
	}
	//if (ball.x < movingObstacles1.x && movingObstacles1.y /*- BALL_HEIGHT*/ < ball.y && ball.y < movingObstacles1.y + PADDLE_HEIGHT)
	//{
	//	ball.dx = -ball.dx;
	//	ball.dy += rand() % 5 - 3;
	//}

	if (ball.y <= 0)
	{
		ball.dy = fabs(ball.dy);
	}
	if (ball.y >= WINDOW_HEIGHT)
		ball.dy = -fabs(ball.dy);
	if (ball.x > WINDOW_WIDTH)
	{
		ball.dy = 0;
		ball.dx = -ball.dx;
		ball.x = MID_X;
		ball.y = MID_Y;
		score1 += 1;
	}
	if (ball.x < -BALL_WIDTH)
	{
		ball.dy = 0;
		ball.dx = -ball.dx;
		ball.x = MID_X;
		ball.y = MID_Y;
		score2 += 1;
	}
}
