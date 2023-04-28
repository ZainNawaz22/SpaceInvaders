#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace sf;
using namespace std;

class Enemy
{
private:
    Texture tex;
    Sprite sprite;
    float speed;

public:
    Enemy(const string &png_path, float speed)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setScale(0.75, 0.75);
        // enemy will be spawned at random x position
        sprite.setPosition(sf::Vector2f(rand() % 780, 0));
        this->speed = speed;
    }
    void move()
    {
        // write code that moves the enemy from top to bottom
        sprite.move(sf::Vector2f(0, speed));
    }

    Sprite &getSprite()
    {
        return sprite;
    }
};