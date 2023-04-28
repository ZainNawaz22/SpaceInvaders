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
    Enemy(const string &png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setScale(0.75, 0.75);
    }
    virtual void move()
    {
    }

    Sprite &getSprite()
    {
        return sprite;
    }
};