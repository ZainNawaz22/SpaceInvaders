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

    Bullet(){
            
            Bullet_tex.loadFromFile("img/PNG/zain.png");
            Bullet_sprite.setTexture(Bullet_tex);
            Bullet_sprite.setScale(0.75, 0.75);
            // enemy will be spawned at random x position
            Bullet_sprite.setPosition(sf::Vector2f(20, 20));
            this->speed = 10;
            this->direction = true;
            
    }
    Bullet(const string &png_path, float speed, Vector2f pos)
    {
        Bullet_tex.loadFromFile(png_path);
        Bullet_sprite.setTexture(Bullet_tex);
        Bullet_sprite.setScale(0.75, 0.75);

        Bullet_sprite.setPosition(Vector2f(pos.x, pos.y));
        this->speed = speed;
        this->direction = direction;
        
        Bullet_sprite.setOrigin(Bullet_sprite.getGlobalBounds().width / 2, 0);

    }

    void move(){
        if(direction == true){
            Bullet_sprite.move(0, -speed);
        }
        else{
            Bullet_sprite.move(0, speed);
        }
    }

    void move(double dt)
    {
        //move the bullet from nosal to the top
        if (direction == true)
        {
            Bullet_sprite.move(0, speed * dt);
        }
        else
        {
            Bullet_sprite.move(0, -speed * dt);
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

    void draw(RenderWindow &window)
    {
        Bullet_sprite.setTexture(Bullet_tex);
        window.draw(Bullet_sprite);
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
