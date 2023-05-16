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
        int direction;
    public:

        Bomb(){
            
            Bomb_tex.loadFromFile("img/PNG/Lasers/laserRed01.png");
            Bomb_sprite.setTexture(Bomb_tex);
            Bomb_sprite.setPosition(sf::Vector2f(20, 20));
            this->speed = 10;
            this->direction = -1;
            
        }
        Bomb(const string &png_path, float speed, Vector2f pos, int direction = -1){
            Bomb_tex.loadFromFile(png_path);
            Bomb_sprite.setTexture(Bomb_tex);
            // enemy will be spawned at random x position
            Bomb_sprite.setPosition(pos);
            this->speed = speed;
            this->direction = direction;
            // set origin to center of sprite
            Bomb_sprite.setOrigin(Bomb_sprite.getGlobalBounds().width/2, 0);
        }

        void move(double dt){
            if(direction == -1){
                Bomb_sprite.move(0, speed * dt);
            }
            else{
                double rad = direction * 3.14159265358979323846 / 180;
                Bomb_sprite.move(speed * cos(rad) * dt, speed * sin(rad) * dt);
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

        Sprite& getSprite(){
            return Bomb_sprite;
        }

        Vector2f getPosition(){
            return Bomb_sprite.getPosition();
        }

        FloatRect getGlobalBounds(){
            return Bomb_sprite.getGlobalBounds();
        }

        void setDestroy(){
            Bomb_sprite.setPosition(1000, 1000);
        }

        

};