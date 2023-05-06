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

        Bomb(){
            
            Bomb_tex.loadFromFile("img/PNG/zain.png");
            Bomb_sprite.setTexture(Bomb_tex);
            //Bomb_sprite.setScale(0.75, 0.75);
            // enemy will be spawned at random x position
            Bomb_sprite.setPosition(sf::Vector2f(20, 20));
            this->speed = 10;
            this->direction = true;
            cout << "Bomb created" << endl;
            
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

        void move(double delta){
            if (direction == true){
                Bomb_sprite.move(0, speed * delta);
            }
            else{
                Bomb_sprite.move(0, -speed * delta);
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
            Bomb_sprite.setTexture(Bomb_tex);
            window.draw(Bomb_sprite);
        }

        void setSpeed(float speed){
            this->speed = speed;
        }

        float getSpeed(){
            return speed;
        }
};