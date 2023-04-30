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
    const int MAX_BULLETS = 50; // maximum number of bullets
    static Bullet* bullets[MAX_BULLETS] = {nullptr}; // array to store the bullets
    static int num_bullets = 0; // number of bullets currently active

    // update positions of active bullets and delete any that have gone offscreen
    for (int i = 0; i < num_bullets; i++)
    {
        bullets[i]->move();
        if (bullets[i]->getSprite().getPosition().y < 0)
        {
            delete bullets[i];
            bullets[i] = nullptr;
            num_bullets--;
        }
    }

    // create a new bullet if there is room in the array
    if (num_bullets < MAX_BULLETS)
    {
        bullets[num_bullets] = new Bullet("img/PNG/Lasers/laserBlue01.png", 0.5, true);
        bullets[num_bullets]->setPos(sprite.getPosition().x + 20, sprite.getPosition().y);
        num_bullets++;
    }
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

	void drawBullets(sf::RenderWindow &window)
	{
		const int MAX_BULLETS = 50; // maximum number of bullets
		static Bullet* bullets[MAX_BULLETS] = { nullptr }; // array to store the bullets
		static int num_bullets = 0; // number of bullets currently active

		// update positions of active bullets and delete any that have gone offscreen
		for (int i = 0; i < num_bullets; i++)
		{
			bullets[i]->move();
			if (bullets[i]->getSprite().getPosition().y < 0)
			{
				delete bullets[i];
				bullets[i] = nullptr;
				num_bullets--;
			}
		}

		// create a new bullet if there is room in the array
		if (num_bullets < MAX_BULLETS)
		{
			bullets[num_bullets] = new Bullet("img/PNG/Lasers/laserBlue01.png", 0.5, true);
			bullets[num_bullets]->setPos(sprite.getPosition().x + 20, sprite.getPosition().y);
			num_bullets++;
		}

		// draw the bullets
		for (int i = 0; i < num_bullets; i++)
		{
			window.draw(bullets[i]->getSprite());
		}
	}
};
