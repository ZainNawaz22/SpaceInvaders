#include <SFML/Graphics.hpp>
#include <time.h>
#include "player.h"
#include "Enemy.h"
#include "Invaders.h"
//#include "Bomb.h"
//#include "Bullet.h"


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
    int enemyCount; // number of enemies

    Bullet *b; // bullet
    Invaders *I; // invaderss

        // E = new Enemy[enemyCount];

    Bomb *bombsArray; // array of bombs
    int bombCount; // number of bombs
    Invaders *invadersArray; // array of invaders
    int invadersCount; // number of invaders

    Lives livesArray; // array of lives

    

    Game()
    {
        p = new Player("img/player_ship.png");
        E = new Enemy("img/enemy_1.png");
        b = new Bullet("img/PNG/zain.png", 0.01, true);
        I = new Invaders("img/enemy_1.png");
        // draw the Lives Addons from Addons.h
        // enemyCount = 1;
        // E = new Enemy[enemyCount];
        
        E = nullptr;
        enemyCount = 0;


        bombsArray = new Bomb[0];
        bombCount = 0;

        invadersArray = new Invaders[0];
        invadersCount = 0;

        bg_texture.loadFromFile("img/background.jpg");
        background.setTexture(bg_texture);
        background.setScale(2.25, 1.35);
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

    void spawnBomb()
    {
        Bomb b;
        addBomb(b);
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

    void drawEnemies(RenderWindow &window)
    {
        for (int i = 0; i < enemyCount; i++)

        {
            E[i].move();
            window.draw(E[i].getSprite());
            cout<<"enemyCount: "<<i<<endl;
        }

       
    }


    void start_game()
    {
        srand(time(0));
        RenderWindow window(VideoMode(780, 700), title);
        // set fps
        window.setFramerateLimit(60);
      
        Clock clock;
        float timer = 0;

        Invaders I("img/enemy_1.png");
        addInvader(I);

        Clock deltaClock;
        double dt;



        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            dt = deltaClock.restart().asMicroseconds()/1000000.0f;
            
            timer += time;
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close();          // close the game
            }

            if (Keyboard::isKeyPressed(Keyboard::Left))  // If left key is pressed
                p->move("l");                            // Player will move to left
            if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                p->move("r");                            // player will move to right
            if (Keyboard::isKeyPressed(Keyboard::Up))    // If up key is pressed
                p->move("u");                            // playet will move upwards
            if (Keyboard::isKeyPressed(Keyboard::Down))  // If down key is pressed
                p->move("d");                            // player will move downwards

            if(Keyboard::isKeyPressed(Keyboard::Space)){
                E->move();

            }
            ////////////////////////////////////////////////
            /////  Call your functions here            ////

            p->wrap();
          
            

            
          

            //////////////////////////////////////////////


            
           
         

            window.clear(Color::Black); // clears the screen
            window.draw(background);    // setting background
            window.draw(p->sprite);     // setting player on screen

            for(int i = 0; i < invadersCount; i++)
            {
                invadersArray[i].move(dt);
                window.draw(invadersArray[i].getSprite());
            }
            

            



           
            window.display(); // Displying all the sprites
        }
    }


};
