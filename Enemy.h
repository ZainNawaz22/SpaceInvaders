#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>
#include "Bomb.h"

using namespace sf;
using namespace std;

class Enemy
{
protected:
    Texture tex;
    Sprite sprite;

public:

    Enemy()
    {
        tex.loadFromFile("img/enemy_1.png");
        sprite.setTexture(tex);
        sprite.setScale(0.75, 0.75);
        // enemy will be spawned at random x position
        // sprite.setPosition(sf::Vector2f(0, 0));
    }

    Enemy(const string &png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setScale(0.75, 0.75);
    }

    void move()
    {
        //write code that moves the bullet from bottom to top
        sprite.move(sf::Vector2f(0, 0.4));
    }
    void draw(RenderWindow &window)
    {
        sprite.setTexture(tex);
        window.draw(sprite);
    }
    Vector2f getPosition()
    {
        return sprite.getPosition();
    }
    Vector2f getCenter(){
        return Vector2f(sprite.getPosition().x + sprite.getGlobalBounds().width/2, sprite.getPosition().y + sprite.getGlobalBounds().height/2);
    }

    void setPosition(Vector2f pos)
    {
        sprite.setPosition(pos);
    }

    Sprite& getSprite()
    {
        return sprite;
    }

    //get global bounds of the sprite
    FloatRect getGlobalBounds()
    {
        return sprite.getGlobalBounds();
    }
};