#include "Enemy.h"

class Invaders: public Enemy
{
    protected:
        int bombRate;
        int bombSpeed;
        int bombCount;
        int moveDirection;
        double bombTimer;
        bool dropBomb;
        int velocity;
    public:
        Invaders(){
            bombTimer = 0;
            velocity = 100;
            bombRate = 1;
            bombSpeed = 1;
            bombCount = 1;
            moveDirection = 1;
            sprite.setPosition(200, 0);
        }
        Invaders(const string &png_path): Enemy(png_path){
            bombTimer = 0;
            velocity = 100;
            bombRate = 1;
            bombSpeed = 1;
            bombCount = 1;
            moveDirection = 1;
            // randomize x position between 0 and 680
            sprite.setPosition(rand() % 680, 0);
        };

        void move(double deltaTime = 0){
    
            sprite.move(sf::Vector2f(0, velocity * moveDirection * deltaTime));
            if(sprite.getPosition().y > 450){
                moveDirection *= -1;
                sprite.setPosition(sprite.getPosition().x, 450);
            }
            if(sprite.getPosition().y < 0){
                moveDirection *= -1;
                sprite.setPosition(sprite.getPosition().x, 0);
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
            if(dropBomb == true){
                bombTimer = 0;
                dropBomb = false;
                return true;
            }
            return false;
            
        }

        void onFrame(double deltaTime){
            bombTimer += deltaTime;
            if(bombTimer > bombRate){
                dropBomb = true;
            }
        };
};

class Alpha: public Invaders{
    public:
        Alpha(): Invaders(){
        }
        Alpha(const string &png_path): Invaders(png_path){
            setBombRate(5);
        };
};

class Beta: public Invaders{
    public:
        Beta(): Invaders(){
        }
        Beta(const string &png_path): Invaders(png_path){
            setBombRate(3);
        };
};


class Gamma: public Invaders{
    public:
        Gamma(): Invaders(){
        }
        Gamma(const string &png_path): Invaders(png_path){
            setBombRate(2);
        };
};