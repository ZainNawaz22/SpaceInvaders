#include<iostream>
#include<SFML/Graphics.hpp>
#include "Enemy.h"

using namespace std;
using namespace sf;

class Dragon:public Enemy{
    private:
    int bombrate;
    double bombTimer;
    bool dropBomb;
    int velocity;

    public:
    Dragon(){
        bombrate = 1;
        bombTimer = 0;
        velocity = 100;
        dropBomb = false;
        sprite.setPosition(200, 0);
    }
    Dragon(const string &png_path): Enemy(png_path){
        bombrate = 1;
        bombTimer = 0;
        velocity = 100;
        dropBomb = false;
        sprite.setPosition(rand() % 680, 0);
        
    };


    void draw(RenderWindow &window){
        
        sprite.setTexture(tex);
        window.draw(sprite);
    }

    //get position of the dragon
    Vector2f getPosition(){
        return sprite.getPosition();
    }

    //get center of the dragon
    Vector2f getCenter(){
        return Vector2f(sprite.getPosition().x + sprite.getGlobalBounds().width/2, sprite.getPosition().y + sprite.getGlobalBounds().height/2);
    }

    FloatRect getGlobalBounds(){
        return sprite.getGlobalBounds();
    }
    //make the move function that the sprite from left to right and right to left
    void moved(double deltaTime = 0){
        if(sprite.getPosition().x < 0){
            velocity = 100;
        }
        else if(sprite.getPosition().x > 640){
            velocity = -100;
        }
        sprite.move(velocity * deltaTime, 0);
    };

    void setBombTimer(double deltaTime){
        bombTimer += deltaTime;
        if(bombTimer >= bombrate){
            dropBomb = true;
        }
    }

    void setBombRate(int rate){
        bombrate = rate;
    }

    bool getDropBomb(){
        if(dropBomb == true){
            bombTimer = 0;                      
            dropBomb = false;
            return true;
        }
        return false;
    }

};

class Monster:public Enemy{
    private:
    int bombrate;
    double bombTimer;
    bool dropBomb;
    int velocity;

    public:
    Monster(){
        bombrate = 1;
        bombTimer = 0;
        velocity = 100;
        dropBomb = false;
        sprite.setPosition(200, 0);
    }
    Monster(const string &png_path): Enemy(png_path){
        bombrate = 1;
        bombTimer = 0;
        velocity = 100;
        dropBomb = false;
        sprite.setPosition(rand() % 680, 0);
        sprite.setScale(0.5,0.5);
        
    };

    void draw(RenderWindow &window){
        
        sprite.setTexture(tex);
        window.draw(sprite);
    }

    //get position of the dragon
    Vector2f getPosition(){
        return sprite.getPosition();
    }

    //get center of the dragon
    Vector2f getCenter(){
        return Vector2f(sprite.getPosition().x + sprite.getGlobalBounds().width/2, sprite.getPosition().y + sprite.getGlobalBounds().height/2);
    }

    FloatRect getGlobalBounds(){
        return sprite.getGlobalBounds();
    }
    //make the move function that the sprite from left to right and right to left
    void moved(double deltaTime = 0){
        if(sprite.getPosition().x < 0){
            velocity = 100;
        }
        else if(sprite.getPosition().x > 640){
            velocity = -100;
        }
        sprite.move(velocity * deltaTime, 0);
    };

    void setBombTimer(double deltaTime){
        bombTimer += deltaTime;
        if(bombTimer >= bombrate){
            dropBomb = true;
        }
    }

    void setBombRate(int rate){
        bombrate = rate;
    }

    bool getDropBomb(){
        if(dropBomb == true){
            bombTimer = 0;                      
            dropBomb = false;
            return true;
        }
        return false;
    }
};
