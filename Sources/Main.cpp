#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 500;

const int PADDLE_WIDTH = 12;
const int PADDLE_HEIGHT = 70;

const int BALL_WIDTH = 12;
const int BALL_HEIGHT = 12;

struct Ball
{
	float x, y, dx, dy;
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
	const float dy = 8.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if (paddle1.y < WINDOW_HEIGHT-PADDLE_HEIGHT)
		paddle1.y += dy;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if(paddle1.y > 0)
		paddle1.y -= dy;
}
void UpdatePositionPaddle2(Paddle2& paddle2)
{
	const float dy = 8.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (paddle2.y < WINDOW_HEIGHT - PADDLE_HEIGHT)
		paddle2.y += dy;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (paddle2.y > 0)
			paddle2.y -= dy;
}
void UpdatePositionBall(Ball& ball, Paddle1& paddle1, Paddle2& paddle2)
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
	if (ball.y <= 0)
		ball.dy = fabs(ball.dy);
	if (ball.y >= WINDOW_HEIGHT)
		ball.dy = -fabs(ball.dy);
	if (ball.x > WINDOW_WIDTH || ball.x < -BALL_WIDTH)
	{
		ball.dy = 0;
		ball.dx = -ball.dx;
		ball.x = 394;
		ball.y = 250;
	}
}

int main()
{
	srand((unsigned)time(nullptr));
	RenderWindow app(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ping Pong");
	app.setFramerateLimit(60);

	Texture tBackground, tPaddle1, tPaddle2, tBall;
	tBackground.loadFromFile("Resources/Background.png");
	tPaddle1.loadFromFile("Resources/Paddle.png");
	tPaddle2.loadFromFile("Resources/Paddle2.png");
	tBall.loadFromFile("Resources/Ball.png");

	sf::Font font;
	font.loadFromFile("Resources/Tuffy.ttf");

	sf::Text Score1;
	Score1.setFont(font);
	Score1.setString("0");
	Score1.setCharacterSize(80);
	Score1.setFillColor(sf::Color::White);

	sf::Text Score2;
	Score2.setPosition(750, 0);
	Score2.setFont(font);
	Score2.setString("0");
	Score2.setCharacterSize(80);
	Score2.setFillColor(sf::Color::White);

	Sprite sprBackground(tBackground);
	Sprite sprPaddle1(tPaddle1);
	Sprite sprBall(tBall);
	Sprite sprPaddle2(tPaddle2);

	Ball ball;
	ball.x = 394;
	ball.y = 250;
	ball.dx = 10;
	ball.dy = 0;

	Paddle1 paddle1;
	paddle1.x = 0;
	paddle1.y = WINDOW_HEIGHT / 2;

	Paddle2 paddle2;
	paddle2.x = WINDOW_WIDTH - 12;
	paddle2.y = WINDOW_HEIGHT / 2;

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
		UpdatePositionBall(ball, paddle1 ,paddle2);

		app.draw(sprBackground);

		sprPaddle1.setPosition(paddle1.x, paddle1.y);
		app.draw(sprPaddle1);

		sprPaddle2.setPosition(paddle2.x, paddle2.y);
		app.draw(sprPaddle2);

		app.draw(sprBall);
		sprBall.setPosition(ball.x, ball.y);

		app.draw(Score1);
		app.draw(Score2);

		app.display();
	}

	return 0;
}