#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include <time.h>
#include <math.h>



using namespace sf;
using namespace std;

class Bomb{
    private:
        Texture Bomb_tex;
        Sprite Bomb_sprite;
        float speed;
        bool direction;
    public:

        Sprite getSprite(){
            return Bomb_sprite;
        }

        Bomb(){
            Bomb_tex.loadFromFile("img/PNG/zain.png");
            Bomb_sprite.setTexture(Bomb_tex);
            Bomb_sprite.setScale(0.75, 0.75);
            // enemy will be spawned at random x position
            Bomb_sprite.setPosition(sf::Vector2f(0, 0));
            this->speed = 0;
            this->direction = true;
        }
        Bomb(const string &png_path, float speed){
            Bomb_tex.loadFromFile(png_path);
            Bomb_sprite.setTexture(Bomb_tex);
            Bomb_sprite.setScale(0.75, 0.75);
            // enemy will be spawned at random x position
            Bomb_sprite.setPosition(sf::Vector2f(0, 0));
            this->speed = speed;
            this->direction = true;
        }

        void move(){
            
            //write code that moves the bullet from bottom to top
            if (direction == true){
                Bomb_sprite.move(sf::Vector2f(0, -speed));
            }
            else{
                Bomb_sprite.move(sf::Vector2f(0, speed));
            }
            
        }

        void setPos(float x, float y){
            Bomb_sprite.setPosition(sf::Vector2f(x, y));
        }

        void setDir(bool dir){
            direction = dir;
        }

        bool getDir(){
            return direction;
        }

        void draw(RenderWindow &window){
            window.draw(Bomb_sprite);
        }

        void setSpeed(float speed){
            this->speed = speed;
        }

        float getSpeed(){
            return speed;
        }
};