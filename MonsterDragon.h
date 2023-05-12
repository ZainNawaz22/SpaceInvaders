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

};