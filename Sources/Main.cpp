#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 500;

const int PADDLE_WIDTH = 12;
const int PADDLE_HEIGHT = 70;

struct Ball
{
	float x, y;
};
struct Paddle1
{
	float x, y;
};
struct Paddle2
{
	float x, y;
};

void UpdatePositionPaddle1(Paddle1& paddle1)
{
	const float dy = 1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		paddle1.y += dy;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		paddle1.y -= dy;
}
void UpdatePositionPaddle2(Paddle2& paddle2)
{
	const float dy = 1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		paddle2.y += dy;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		paddle2.y -= dy;
}
void UpdatePositionBall(Ball& ball, float& dy)
{
	//const float dx = 1.0f;
	ball.y += dy;
}

int main()
{
	srand((unsigned)time(nullptr));
	RenderWindow app(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ping Pong");
	
	Texture tBackground, tPaddle1, tPaddle2, tBall;
	tBackground.loadFromFile("Resources/Background.png");
	tPaddle1.loadFromFile("Resources/Paddle.png");
	tPaddle2.loadFromFile("Resources/Paddle2.png");
	tBall.loadFromFile("Resources/Ball.png");

	Sprite sprBackground(tBackground);
	Sprite sprPaddle1(tPaddle1);
	Sprite sprBall(tBall);
	Sprite sprPaddle2(tPaddle2);

	Ball ball;
	ball.x = 394;
	ball.y = 250;

	Paddle1 paddle1;
	paddle1.x = 0;
	paddle1.y = WINDOW_HEIGHT / 2;

	Paddle2 paddle2;
	paddle2.x = WINDOW_WIDTH - 12;
	paddle2.y = WINDOW_HEIGHT / 2;

	float dy = 0.5;

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}

		UpdatePositionPaddle1(paddle1);
		UpdatePositionPaddle2(paddle2);
		UpdatePositionBall(ball, dy);
		
		app.draw(sprBackground);

		sprPaddle1.setPosition(paddle1.x, paddle1.y);
		app.draw(sprPaddle1);

		sprPaddle2.setPosition(paddle2.x, paddle2.y);
		app.draw(sprPaddle2);

		app.draw(sprBall);
		sprBall.setPosition(ball.x, ball.y);

		app.display();
	}

	return 0;
}