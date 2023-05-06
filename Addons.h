#pragma once

//#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace sf;
using namespace std;

class Addon{
    protected:
        int x;
        int y;
        int velX;
        int velY;
        int type;
        Texture texture;
        Sprite sprite;
    public:
        Addon(){
            x = 0;
            y = 0;
            velX = 0;
            velY = 0;
            type = 0;
        }

        Sprite getSprite(){
            return sprite;
        }
        int getType(){
            return type;
        }
        
};

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
        void draw(RenderWindow &window){
            sprite.setPosition(x, y);
            window.draw(sprite);
        }

        void move(){
            x += velX;
            y += velY;
        }
};

class Fire: public Addon{
    public:
        Fire(){
            texture.loadFromFile("img/fire.png");
            sprite.setTexture(texture);
            sprite.setScale(0.1, 0.1);
            type = 2; //2 is fire
            x = rand() % 700;
            y = 0;
            // random velocity
            velX = rand() % 10;
            velY = rand() % 10;
        };
        
        void draw(RenderWindow &window){
            sprite.setPosition(x, y);
            window.draw(sprite);
        };
        void move(){
            x += velX;
            y += velY;
        };

        
};

class Danger: public Addon{
    public:
        Danger(){
            texture.loadFromFile("img/danger.png");
            sprite.setTexture(texture);
            sprite.setScale(0.1, 0.1);
            type = 3; //3 is danger
            x = rand() % 700;
            y = 0;
            // random velocity
            velX = rand() % 10;
            velY = rand() % 10;
        }
        
        void draw(RenderWindow &window){
            sprite.setPosition(x, y);
            window.draw(sprite);
        }
        void move(){
            x += velX;
            y += velY;
        }
};

class Lives: public Addon{
    public:
        Lives(){
            texture.loadFromFile("img/PNG/Power-ups/aa.png");
            sprite.setTexture(texture);
            sprite.setScale(0.1, 0.1);
            type = 4; //4 is lives
            x = rand() % 700; // random x position
            y = 0; // start at the top of the screen
            // random velocity
            velX = rand() % 10;
            velY = rand() % 10;
        }
        void draw(RenderWindow &window){
            sprite.setPosition(x, y);
            window.draw(sprite);
        }
        void move(){
            x += velX;
            y += velY;
        }

        // get sprite of the addon

        Sprite& getSprite(){
            return sprite;
        }
};

