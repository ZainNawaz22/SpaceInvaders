#include <SFML/Graphics.hpp>
#include <string.h>
#include "Bullet.h"
using namespace sf;
class Player
{
public:
	Texture tex;
	Sprite sprite;
	float speed = 0.1;
	int x, y;
	Player(std::string png_path)
	{

		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 340;
		y = 650;
		sprite.setPosition(sf::Vector2f(x, y));
		sprite.setScale(0.75, 0.75);
	}
	void fire()
	{
		// Bullet b("img/PNG/zain.png", 0.01, true);
		// b.setPos(sprite.getPosition().x + 20, sprite.getPosition().y);
		// //bullets.push_back(b);
	}
	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;
		if (s == "l")
			delta_x = -1;

		else if (s == "r")
			delta_x = 1;
		// move the player right
		if (s == "u")
			delta_y = -1;
		else if (s == "d")
			delta_y = 1;

		delta_x *= speed;
		delta_y *= speed;

		sprite.move(sf::Vector2f(delta_x, delta_y));
	}

	// make the functions that the screeen acts as a wrap around the player enters from one side and exits from the other side of the screen and same for the top and bottom

	void wrap()
	{
		if (sprite.getPosition().x > 780)
			sprite.setPosition(sf::Vector2f(0, sprite.getPosition().y));
		else if (sprite.getPosition().x < 0)
			sprite.setPosition(sf::Vector2f(780, sprite.getPosition().y));
		if (sprite.getPosition().y > 700)
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 0));
		else if (sprite.getPosition().y < 0)
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 700));
	}

	// make the function that constantly checks the players position

	int get_x()
	{
		return sprite.getPosition().x;
	}

	int get_y()
	{
		return sprite.getPosition().y;
	}
};
