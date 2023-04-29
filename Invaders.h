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
    public:
        Invaders(){
            bombRate = 1;
            bombSpeed = 1;
            bombCount = 1;
            moveDirection = 1;
        }
        Invaders(const string &png_path): Enemy(png_path){
            bombRate = 1;
            bombSpeed = 1;
            bombCount = 1;
            moveDirection = 1;
        };

        void move(){
            // move sprite in x direction
            sprite.move(moveDirection, 0);
            // if sprite reaches the end of the screen
            if(sprite.getPosition().x > 700 || sprite.getPosition().x < 0){
                // move sprite in y direction
                sprite.move(0, 50);
                // change direction
                moveDirection = -moveDirection;
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