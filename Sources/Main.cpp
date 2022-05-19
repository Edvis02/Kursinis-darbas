#include <SFML/Graphics.hpp>
#include <format>
#include "Defines.h"
#include "Objects.h"
#include "Utils.h"

using namespace sf;
using namespace std;

int main()
{
	srand((unsigned)time(nullptr));
	RenderWindow app(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ping Pong");
	app.setFramerateLimit(60);

	Texture tBackground, tPaddle1, tPaddle2, tBall, tMovingObstacle1, tMovingObstacle2;
	tBackground.loadFromFile("Resources/Background.png");
	tPaddle1.loadFromFile("Resources/Paddle.png");
	tPaddle2.loadFromFile("Resources/Paddle.png");
	tBall.loadFromFile("Resources/Ball.png");
	tMovingObstacle1.loadFromFile("Resources/Paddle.png");
	tMovingObstacle2.loadFromFile("Resources/Paddle.png");

	sf::Font font;
	font.loadFromFile("Resources/Tuffy.ttf");

	sf::Text Score1;
	Score1.setFont(font);
	Score1.setString("0");
	Score1.setCharacterSize(80);
	Score1.setFillColor(sf::Color::White);

	sf::Text Score2;
	Score2.setPosition(710, 0);
	Score2.setFont(font);
	Score2.setString("0");
	Score2.setCharacterSize(80);
	Score2.setFillColor(sf::Color::White);


	Sprite sprBackground(tBackground);
	Sprite sprPaddle1(tPaddle1);
	Sprite sprBall(tBall);
	Sprite sprPaddle2(tPaddle2);
	Sprite sprtMovingObstacle1(tMovingObstacle1);
	Sprite sprtMovingObstacle2(tMovingObstacle2);

	Ball ball;
	
	Paddle paddle1(0, WINDOW_HEIGHT / 2);
	Paddle paddle2(WINDOW_WIDTH - 12, WINDOW_HEIGHT / 2);

	moving_Obstacles1 movingObstacles1;
	movingObstacles1.x = 197;
	movingObstacles1.y = 430;
	movingObstacles1.dx = 0;
	movingObstacles1.dy = OBSTACLES_SPEED;

	moving_Obstacles2 movingObstacles2;
	movingObstacles2.x = 591;
	movingObstacles2.y = 0;
	movingObstacles2.dx = 0;
	movingObstacles2.dy = OBSTACLES_SPEED;

	float score1 = 0;
	float score2 = 0;
	float dy = 0;
	float dx = BALL_SPEED;

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
				app.close();
		}
		UpdatePositionPaddle1(paddle1);
		UpdatePositionPaddle2(paddle2);
		UpdateMovingObstacles1(movingObstacles1);
		UpdateMovingObstacles2(movingObstacles2);
		UpdatePositionBall(ball, paddle1, paddle2, movingObstacles1, movingObstacles2, score1, score2, dx, dy);

		app.draw(sprBackground);

		sprPaddle1.setPosition(paddle1.GetX(), paddle1.GetY());
		app.draw(sprPaddle1);

		sprPaddle2.setPosition(paddle2.GetX(), paddle2.GetY());
		app.draw(sprPaddle2);

		app.draw(sprBall);
		sprBall.setPosition(ball.GetX(), ball.GetY());

		Score1.setString(std::format("{:.0f}", score1));
		Score2.setString(std::format("{:.0f}", score2));
		app.draw(Score1);
		app.draw(Score2);

		sprtMovingObstacle1.setPosition(movingObstacles1.x, movingObstacles1.y);
		sprtMovingObstacle2.setPosition(movingObstacles2.x, movingObstacles2.y);
		app.draw(sprtMovingObstacle1);
		app.draw(sprtMovingObstacle2);

		app.display();
	}
	
	return 0;
}