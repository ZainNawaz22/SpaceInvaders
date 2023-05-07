#include <SFML/Graphics.hpp>
#include <string.h>
#include "Bullet.h"
#include "Addons.h"
using namespace sf;
class Player
{
public:
	Texture tex;
	Sprite sprite;
	float speed = 100;
	int x, y;

	Player(){
		tex.loadFromFile("img/PNG/zain.png");
		sprite.setTexture(tex);
		x = 340;
		y = 650;
		sprite.setPosition(sf::Vector2f(x, y));
		sprite.setScale(0.75, 0.75);
	}
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
	Bullet *b = new Bullet("img/PNG/zain.png", 10, Vector2f(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y));
	b->setDir(false);
}

	void move(std::string s, double delta_time)
	{
		float direction_x = 0, direction_y = 0;
		if (s == "l")
			direction_x = -1;

		else if (s == "r")
			direction_x = 1;
		// move the player right
		if (s == "u")
			direction_y = -1;
		else if (s == "d")
			direction_y = 1;

		sprite.move(sf::Vector2f(direction_x * speed * delta_time, direction_y * speed * delta_time));
	}

	

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

	// make a function that checks if player collides with addon
	void onAddonPickup(Addon *&a, int &addon_count){
		if (sprite.getGlobalBounds().intersects(a->getSprite().getGlobalBounds())){
			bool addonActive = true;
			if(a->getType() == 1){
				//powerup
				speed += 0.1;
				// create a timer that will run for 10 seconds and then set the speed back to normal
				delete a;
				addon_count--;
				a = nullptr;
			}
			else if(a->getType() == 2){
				//fire
				fire();
			}
			else if(a->getType() == 3){
				//danger
				//speed -= 0.1;
			}
			else if(a->getType() == 4){
				//lives
				//lives++;


			}
		}
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

	Sprite getSprite()
	{
		return sprite;
	}

	// make a function that draws bullets on the screen when the fire function is called



	Vector2f getPosition()
	{
		// return the slightly above from the center of the player vertically but in the center horizontally
		return Vector2f(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y - sprite.getGlobalBounds().height / 2);
	}

	// make a function that checks if the player collides with the enemy bomb
	

	// make a function that sets position of the player
	void setPosition(int x, int y)
	{
		sprite.setPosition(sf::Vector2f(x, y));
	}
};
