#pragma once

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace sf;
using namespace std;

class Addon{
    private:
        int x;
        int y;
        int velX;
        int velY;
        int type;
        Texture texture;
        Sprite sprite;
    public:
        Addon();
        Sprite getSprite(){
            return sprite;
        }
        
}

class PowerUp: public Addon{
    public:
        PowerUp(){
            texture.loadFromFile("img/powerup.png");
            sprite.setTexture(texture);
            sprite.setScale(0.1, 0.1);
            type = 1; //1 is powerup
            x = rand() % 700;
            y = 0;
            // random velocity
            velX = rand() % 10;
            velY = rand() % 10;
        };
        void draw(RenderWindow &window);
        void move();
}

class Fire: public Addon{
    public:
        Fire();
        void draw(RenderWindow &window);
        void move();
}

class Danger: public Addon{
    public:
        Danger();
        void draw(RenderWindow &window);
        void move();
}

class Lives: public Addon{
    public:
        Lives();
        void draw(RenderWindow &window);
        void move();
}

