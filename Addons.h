#pragma once

// #include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace sf;
using namespace std;

class Addon
{
protected:
    int x;
    int y;
    int velX;
    int velY;
    int type;
    Texture texture;
    Sprite sprite;
    int lives = 3;

public:
    Addon()
    {
        x = 0;
        y = 0;
        velX = 0;
        velY = 0;
        type = 0;
    }

    int getType()
    {
        return type;
    }

    // //write function to setDestroy
    // void setDestroy(Sprite &sprite){
    //     sprite.setPosition(1000, 1000);
    // }
    bool intersect(const Sprite &sprite1, const Sprite &sprite2)
    {
        FloatRect shape1 = sprite1.getGlobalBounds();
        FloatRect shape2 = sprite2.getGlobalBounds();

        if (shape1.left + shape1.width > shape2.left && shape1.left < shape2.left + shape2.width &&
            shape1.top + shape1.height > shape2.top && shape1.top < shape2.top + shape2.height)
        {
            // collision detected
            return true;
        }
        return false;
    }
};

class PowerUp : public Addon
{
public:
    PowerUp()
    {
        texture.loadFromFile("img/PNG/Power-ups/powerupRed_bolt.png");
        sprite.setTexture(texture);
        sprite.setScale(0.1, 0.1);
        type = 1; // 1 is powerup
        x = rand() % 700;
        y = 0;
        // random velocity
        velX = rand() % 10;
        velY = rand() % 10;
    }

    PowerUp(const string &png_path, float speed) : Addon()
    {
        texture.loadFromFile(png_path);
        sprite.setTexture(texture);
        sprite.setScale(0.75, 0.75);

        x = rand() % 700; // random x position
        y = 0;            // start at the top of the screen

        sprite.setPosition(Vector2f(x, y));

        sprite.setOrigin(sprite.getGlobalBounds().width / 2, 0);

        cout << "PowerUp created 2" << endl;
    }


    void draw(RenderWindow &window)
    {
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
        window.draw(sprite);
    }

    void move(float dt)
    {
        y += 100 * dt;
        
        sprite.setPosition(x, y);
    }

    Sprite &getSprite()
    {
        return sprite;
    }


    void setDestroy()
    {
        sprite.move(1000, 1000);
        // sprite.setPosition(-800, -800);
    }
    



};

class Fire : public Addon
{
public:
    Fire()
    {
        texture.loadFromFile("img/PNG/Power-ups/bolt_bronze.png");
        sprite.setTexture(texture);
        sprite.setScale(0.1, 0.1);
        type = 2; // 2 is fire
        x = rand() % 700;
        y = 0;
        // random velocity
        velX = rand() % 10;
        velY = rand() % 10;
    };

    Fire(const string &png_path, float speed) : Addon()
    {
        texture.loadFromFile(png_path);
        sprite.setTexture(texture);
        sprite.setScale(0.75, 0.75);

        x = rand() % 700; // random x position
        y = 0;            // start at the top of the screen

        sprite.setPosition(Vector2f(x, y));

        sprite.setOrigin(sprite.getGlobalBounds().width / 2, 0);

        cout << "Fire created 2" << endl;
    }



    void draw(RenderWindow &window)
    {
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
        window.draw(sprite);
    };
    void move(float dt)
    {
        y += 100 * dt;
        sprite.setPosition(x, y);
    };

    Sprite &getSprite()
    {
        return sprite;
    }


    void setDestroy()
    {
        sprite.setPosition(1000, 1000);
    }
   
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    
    Vector2f getPosition()
    {
        return Vector2f(x, y);
    }

};

class Danger : public Addon
{
public:
    Danger()
    {
        texture.loadFromFile("img/PNG/Meteors/meteorBrown_med1.png");
        sprite.setTexture(texture);
        //sprite.setScale(0.1, 0.1);
        type = 3; // 3 is danger
        x = rand() % 700;
        y = 0;
        // random velocity
        velX = 100;
        velY = 100;
    }




    Danger(const string &png_path, float speed) : Addon()
    {
        texture.loadFromFile(png_path);
        sprite.setTexture(texture);
        sprite.setScale(0.75, 0.75);
        x = rand() % 700; // random x position
        y = 0;            // start at the top of the screen
        sprite.setPosition(Vector2f(x, y));
        sprite.setOrigin(sprite.getGlobalBounds().width / 2, 0);
        cout << "Danger created 2" << endl;
    }

    void draw(RenderWindow &window)
    {
        sprite.setTexture(texture);
       
        window.draw(sprite);
    }

    void move(float dt)
    {
        y += 100 * dt;
        sprite.setPosition(x, y);
    };
    Sprite &getSprite()
    {
        return sprite;
    }

    // write setDestroy function that will set the sprite to be destroyed
    void setDestroy()
    {
        sprite.setPosition(1000, 1000);
    }
    // get x and y position
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    // get position using vector
    Vector2f getPosition()
    {
        return Vector2f(x, y);
    }
};

class Lives : public Addon
{
public:
    int l = 3;
    
    Lives()
    {
        texture.loadFromFile("img/PNG/Power-ups/aa.png");
        sprite.setTexture(texture);
        sprite.setScale(0.1, 0.1);
        type = 4;         // 4 is lives
        x = rand() % 700; // random x position
        y = 0;            // start at the top of the screen
        // random velocity
        velX = rand() % 10;
        velY = rand() % 10;
        cout << "Lives created" << endl;
    }

    Lives(const string &png_path, float speed) : Addon()
    {
        texture.loadFromFile(png_path);
        sprite.setTexture(texture);
        sprite.setScale(0.75, 0.75);

        x = rand() % 700; // random x position
        y = 0;            // start at the top of the screen

        sprite.setPosition(Vector2f(x, y));

        sprite.setOrigin(sprite.getGlobalBounds().width / 2, 0);

        cout << "Lives created 2" << endl;
    }
    void draw(RenderWindow &window)
    {
        // set the texture
        sprite.setTexture(texture);
        window.draw(sprite);
    }

    void move(float dt)
    {
        // cout << "Lives move" << endl;
        y += 100 * dt;
        sprite.setPosition(x, y);
    }

    Vector2f getPosition()
    {
        return Vector2f(x, y);
    }

    Sprite &getSprite()
    {
        return sprite;
    }

    // write the intersect function

    
    void setDestroy()
 {
        //sprite.setScale(0, 0);
        cout << "Lives destroyed" << endl;
 }

    // write the function render lives that will render the number of lives on the screen using the font

    void renderLives(RenderWindow &window)
    {
        Font font;
        font.loadFromFile("fonts/GAME_glm.ttf");
        Text text;
        text.setFont(font);
        text.setString("Lives " + to_string(l));
        text.setCharacterSize(24);
        text.setFillColor(Color::White);
        text.setPosition(600, 10);
        window.draw(text);
    }

    // write the function that will return the number of lives
    int getLives()
    {
        return lives;
    }
};
