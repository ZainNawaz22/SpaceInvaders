#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include <time.h>
#include <math.h>



using namespace sf;
using namespace std;

class Bullet
{
private:
    Texture Bullet_tex;
    Sprite Bullet_sprite;
    float speed;
    bool direction;

public:
    Bullet(const string &png_path, float speed, bool direction)
    {
        Bullet_tex.loadFromFile(png_path);
        Bullet_sprite.setTexture(Bullet_tex);
        Bullet_sprite.setScale(0.75, 0.75);
        // enemy will be spawned at random x position
        Bullet_sprite.setPosition(sf::Vector2f(0, 0));
        this->speed = speed;
        this->direction = direction;
    }

    void move()
    {
        
        //write code that moves the bullet from bottom to top
        if (direction == true)
        {
            Bullet_sprite.move(sf::Vector2f(0, -speed));
        }
        else
        {
            Bullet_sprite.move(sf::Vector2f(0, speed));
        }
        
    }

    void setPos(float x, float y)
    {
        Bullet_sprite.setPosition(sf::Vector2f(x, y));
    }

    void setDir(bool dir)
    {
        direction = dir;
    }

    bool getDir()
    {
        return direction;
    }

    void setSpeed(float speed)
    {
        this->speed = speed;
    }

    float getSpeed()
    {
        return speed;
    }

    Sprite &getSprite()
    {
        return Bullet_sprite;
    }


};

