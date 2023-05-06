#include "Enemy.h"

class Invaders: public Enemy
{
    protected:
        int bombRate;
        int bombSpeed;
        int bombCount;
        int moveDirection;
        int bombTimer;
        bool dropBomb;
        int velocity;
    public:
        Invaders(){
            velocity = 100;
            bombRate = 1;
            bombSpeed = 1;
            bombCount = 1;
            moveDirection = 1;
            sprite.setPosition(200, 0);
        }
        Invaders(const string &png_path): Enemy(png_path){
            velocity = 100;
            bombRate = 1;
            bombSpeed = 1;
            bombCount = 1;
            moveDirection = 1;
            sprite.setPosition(200, 0);
        };

        void move(int deltaTime = 0){
    
            sprite.move(sf::Vector2f(0, velocity * moveDirection * deltaTime));
            if(sprite.getPosition().y > 600){
                moveDirection *= -1;
            }

        };
        
        void setBombRate(int rate){
            bombRate = rate;
        }
        void setBombSpeed(int speed){
            bombSpeed = speed;
        }
        void setBombCount(int count){
            bombCount = count;
        }
        int getBombRate(){
            return bombRate;
        }
        int getBombSpeed(){
            return bombSpeed;
        }
        int getBombCount(){
            return bombCount;
        }
        bool getDropBomb(){
            return dropBomb;
        }

        void onFrame(int deltaTime){
            bombTimer += deltaTime;
            if(bombTimer > bombRate){
                bombTimer = 0;
                dropBomb = true;
            }
            move();
        };

        
};