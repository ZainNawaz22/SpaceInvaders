#include <SFML/Graphics.hpp>
#include <time.h>
#include "player.h"
#include "Enemy.h"
#include "Invaders.h"
#include "LevelScore.h"


const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
    Sprite background; // Game background sprite
    Texture bg_texture;
    Player *p; // player
    // add other game attributes
    Enemy *E; // enemy
    int enemyCount=0; // number of enemies
    bool paused;

    
    Invaders *I; // invaderss

        // E = new Enemy[enemyCount];

    Bomb *bombsArray; // array of bombs
    int bombCount; // number of bombs
    Invaders *invadersArray; // array of invaders
    int invadersCount; // number of invaders

    Lives *livesArray; // array of lives
    int livesCount; // number of lives

    Bullet *BulletArray; // array of bullets
    int bulletCount; // number of bullets

    Score *levelScore; // level score
    bool scoreIncrease;

   
    

    

    Game()
    {
        p = new Player("img/player_ship.png");
        levelScore = new Score();
      //  E = new Enemy("img/enemy_1.png");
      //  I = new Invaders("img/enemy_1.png");
        // draw the Lives Addons from Addons.h
        // enemyCount = 1;
        // E = new Enemy[enemyCount];

        livesArray = new Lives[0];
        livesCount = 0;
        paused = false;
        
        E = nullptr;
        enemyCount = 0;


        bombsArray = new Bomb[0];
        bombCount = 0;

        BulletArray = new Bullet[0];
        bulletCount = 0;

        invadersArray = new Invaders[0];
        invadersCount = 0;

        

        bg_texture.loadFromFile("img/background.jpg");
        background.setTexture(bg_texture);
        background.setScale(2.25, 1.35);

        scoreIncrease = false;
    }
    void addBomb(Bomb &b)
    {
        Bomb *temp = new Bomb[bombCount + 1];
        for (int i = 0; i < bombCount; i++)
        {
            temp[i] = bombsArray[i];
        }
        temp[bombCount] = b;
        bombCount++;
        bombsArray = temp;
    }
    

    void spawnBomb(Vector2f pos)
    {
        Bomb b("img/PNG/zain.png", 150, pos);
        addBomb(b);
    }

    void addBullet(Bullet &b)
    {
        Bullet *temp = new Bullet[bulletCount + 1];
        for (int i = 0; i < bulletCount; i++)
        {
            temp[i] = BulletArray[i];
        }
        temp[bulletCount] = b;
        bulletCount++;
        BulletArray = temp;
    }

    void spawnBullet(Vector2f pos)
    {
        Bullet b("img/PNG/Lasers/laserBlue01.png", 150, pos);
        addBullet(b);
    }

    void addInvader(Invaders &i)
    {
        Invaders *temp = new Invaders[invadersCount + 1];
        for (int i = 0; i < invadersCount; i++)
        {
            temp[i] = invadersArray[i];
        }
        temp[invadersCount] = i;
        invadersCount++;
        invadersArray = temp;
    }

    void addEnemy(Enemy &e)
    {
        Enemy *temp = new Enemy[enemyCount + 1];
        for (int i = 0; i < enemyCount; i++)
        {
            temp[i] = E[i];
        }
        temp[enemyCount] = e;
        enemyCount++;
        delete[] E;
        E = temp;
    }

    void addLives(Lives &l)
    {
        Lives *temp = new Lives[livesCount + 1];
        for (int i = 0; i < livesCount; i++)
        {
            temp[i] = livesArray[i];
        }
        temp[livesCount] = l;
        livesCount++;
        livesArray = temp;
    }

    void spawnLives()
    {
        Lives l("img/PNG/UI/playerLife1_blue.png", 150);

        addLives(l);
        
    }

    void start_game()
    {
        srand(time(0));
        RenderWindow window(VideoMode(780, 700), title);
        // set fps
        window.setFramerateLimit(60);
      
        Clock clock;
        float timer = 0;

        Clock deltaClock;
        double dt;

        double invaderSpawnTimer = 5;
        double bulletSpawnTimer = 1;
        double timer2 = 2;
        double addonSpawnTimer = 10;

        paused = false;
        

        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            dt = deltaClock.restart().asMicroseconds()/1000000.0f;
            
            timer += time;
            invaderSpawnTimer -= dt;
            bulletSpawnTimer -= dt;
            timer2 -= dt;
            addonSpawnTimer -= dt;
            
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close();          // close the game
            }

            // puase the game
            if (Keyboard::isKeyPressed(Keyboard::P))
            {
                paused = !paused;
            }
            if (Keyboard::isKeyPressed(Keyboard::Left) && !paused)  // If left key is pressed
                p->move("l", dt);                            // Player will move to left
            if (Keyboard::isKeyPressed(Keyboard::Right) && !paused) // If right key is pressed
                p->move("r", dt);                            // player will move to right
            if (Keyboard::isKeyPressed(Keyboard::Up) && !paused)    // If up key is pressed
                p->move("u", dt);                            // playet will move upwards
            if (Keyboard::isKeyPressed(Keyboard::Down) && !paused)  // If down key is pressed
                p->move("d", dt);                            // player will move downwards

            if(Keyboard::isKeyPressed(Keyboard::Space) && !paused){
                
                if(bulletSpawnTimer <= 0){
                    spawnBullet(p->getPosition());
                    bulletSpawnTimer = 0.25;
                }
            }


            
                
            ////////////////////////////////////////////////
            /////  Call your functions here            ////

            p->wrap();
            

          
            

            
          

            //////////////////////////////////////////////


            
           
         

            window.clear(Color::Black); // clears the screen
            window.draw(background);    // setting background
            //             // draw all bullets

            for(int i = 0; i < bulletCount; i++)
            {
                if (!paused) BulletArray[i].move(dt);
                BulletArray[i].draw(window);
            
                // check if the bullet sprite intersects with enemy sprite and delete both
                for(int j = 0; j < invadersCount; j++)
                {

                    if(BulletArray[i].getSprite().getGlobalBounds().intersects(invadersArray[j].getSprite().getGlobalBounds()))
                    {
                        scoreIncrease = true;
                        BulletArray[i].setDestroy();
                        invadersArray[j].setDestroy(true);
                    }
                }
                if(invadersArray[i].getDestroy())
                {
                    invadersArray[i] = invadersArray[invadersCount - 1];
                    invadersCount--;
                }
                
    
                

                //if bullet goes out of screen, delete it
                if(BulletArray[i].getPosition().y < 0)
                {
                    BulletArray[i] = BulletArray[bulletCount - 1];
                    bulletCount--;
                

                }
            
            }
            
            window.draw(p->sprite);     // setting player on screen

            for(int i = 0; i < livesCount; i++)
            {
                //cout<<"lives_count"<<livesCount<<endl;
                if (!paused) livesArray[i].move(dt);
                livesArray[i].draw(window);
                livesArray[i].move(dt);

            }
            // draw all bombs
            for (int i = 0; i < bombCount; i++)
            {
                if (!paused) bombsArray[i].move(dt);
                bombsArray[i].draw(window);

                for(int j = 0; j < bombCount; j++)
                {
                    if(bombsArray[i].getSprite().getGlobalBounds().intersects(p->getSprite().getGlobalBounds()))
                    {
                        
                        bombsArray[i].setDestroy();
                        p->setDestroy(true);
                    
                    }
                }
                // if bomb goes out of screen, delete it
                if (bombsArray[i].getPosition().y > 700)
                {
                    bombsArray[i] = bombsArray[bombCount - 1];
                    bombCount--;
                }
            }

            for(int i = 0; i < invadersCount; i++)
            {
                if (!paused) invadersArray[i].move(dt);
                invadersArray[i].draw(window);
            }

            if(paused){
                

                
                window.display();
                continue;
            }


            // spawn invaders
            if(invaderSpawnTimer <= 0)
            {
                // choose random number between 1 and 3
                int random = rand() % 3 + 1;
                // if random is 1, spawn Alpha
                if(random == 1)
                {
                    Alpha I("img/enemy_1.png");

                    addInvader(I);
                    
                }
                // if random is 2, spawn Beta
                else if(random == 2)
                {
                    Beta I("img/enemy_2.png");
                    addInvader(I);
                }
                // if random is 3, spawn Gamma
                else if(random == 3)
                {
                    Gamma I("img/enemy_3.png");
                    addInvader(I);
                }
                invaderSpawnTimer = 5;

            }
            

            // loop through all the invaders
            for (int i = 0; i < invadersCount; i++)
            {
                // call onFrame
                invadersArray[i].onFrame(dt);
                // if invader.getdropBomb() == true
                if (invadersArray[i].getDropBomb()){
                    spawnBomb(invadersArray[i].getCenter());
                }
            }

            

            // spawn addons
            if(addonSpawnTimer <= 0)
            {
                // choose random number between 1 and 3
                int random = rand() % 3 + 1;
                // if random is 1, Lives
                if(random == 1 || true)  
                {
                    spawnLives();
                }
                // if random is 2....

                // randomize spawn timer between 10 and 20
                addonSpawnTimer = rand() % 10 + 10;
            }
            if(scoreIncrease){
                levelScore->update();
                scoreIncrease = false;
            }
            levelScore->draw(window);
            
            window.display(); // Displying all the sprites
        }
        
    }
};
