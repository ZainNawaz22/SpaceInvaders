
#include <SFML/Graphics.hpp>
#include <time.h>
#include "player.h"
#include "Enemy.h"
#include "Addons.h"
// #include "Bullet.h"


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
    Bullet *b; // bullet
    Addon *addon; // addons
    int addonCount = 0;

    

    Game()
    {
        p = new Player("img/player_ship.png");
        E = new Enemy("img/enemy_1.png", 0.01);
        b = new Bullet("img/PNG/zain.png", 0.01, true);
      
        

        bg_texture.loadFromFile("img/background.jpg");
        background.setTexture(bg_texture);
        background.setScale(2.25, 1.35);
    }
    void checkAndSpawnAddons(int &addonTimer)
    {
        // call checkAndSpawnAddons every 10 seconds
        if(addonTimer < 10)
        {
            return;
        }
        addonTimer = 0;
        // theres a 1 in 100 chance of spawning an addon
        int spawnChance = rand() % 100 + 1;
        if(spawnChance != 1)
        {
            return;
        }
        if(addonCount < 1)
        {
            // spawn a random addon between 1 and 4
            int addonType = rand() % 4 + 1;
            if(addonType == 1)
            {
                addon = new PowerUp();
            }
            else if(addonType == 2)
            {
                addon = new Fire();
            }
            else if(addonType == 3)
            {
                addon = new Danger();
            }
            else if(addonType == 4)
            {
                addon = new Lives();
            }
            addonCount++;
        }
    }

    void checkAndRemoveAddons()
    {
        if(addon->getSprite().getPosition().y > 700)
        {
            delete addon;
            addonCount--;
            addon = nullptr;
        }
    }


    void start_game()
    {
        srand(time(0));
        RenderWindow window(VideoMode(780, 700), title);
      
        Clock clock;
        float timer = 0;
        float addonTimer = 0;

        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            addonTimer += time;
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close();          // close the game
            }

            p->check_input();
            
            ////////////////////////////////////////////////
            /////  Call your functions here            ////
            p->wrap();
            E->move();
            b->move();
            b->setPos(p->sprite.getPosition().x + 20, p->sprite.getPosition().y);
            if(addon != nullptr)
            {
                addon->move();
            }
            //

            
            checkAndSpawnAddons(addonTimer);
            checkAndRemoveAddons();
            //////////////////////////////////////////////////

            
          

            //////////////////////////////////////////////

            

            window.clear(Color::Black); // clears the screen
            window.draw(background);    // setting background
            window.draw(p->sprite);     // setting player on screen
            window.draw(E->getSprite()); // setting enemy on screen
            window.draw(b->getSprite()); // setting bullet on screen
            if(addon != nullptr)
            {
                window.draw(addon->getSprite());
            }
           
            window.display(); // Displying all the sprites
        }
    }
};
