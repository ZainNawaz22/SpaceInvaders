#include <SFML/Graphics.hpp>
#include <time.h>
#include "player.h"
#include "Enemy.h"
#include "Invaders.h"
#include "LevelScore.h"
#include "MonsterDragon.h"

const char title[] = "OOP-Project, Spring-2023";
using namespace sf;
using namespace std;

class Game
{
public:
    Sprite background; // Game background sprite
    Texture bg_texture;
    Player *p; // player
    // add other game attributes
    Enemy *E;           // enemy
    int enemyCount = 0; // number of enemies
    bool paused;
    bool disappear;
    bool intersect;

    Invaders *I; // invaderss

    // E = new Enemy[enemyCount];

    Bomb *bombsArray;        // array of bombs
    int bombCount;           // number of bombs
    Invaders *invadersArray; // array of invaders
    int invadersCount;       // number of invaders

    Lives *livesArray; // array of lives
    int livesCount;    // number of lives

    Bullet *BulletArray; // array of bullets
    int bulletCount;     // number of bullets

    Score *levelScore; // level score
    bool scoreIncrease;

    Danger *dangerArray; // array of danger
    int dangerCount;     // number of danger

    Fire *fireArray; // array of fire
    int fireCount;   // number of fire

    PowerUp *powerUpArray; // array of powerUp
    int powerUpCount;      // number of powerUp

    Dragon *DragonArray; //  dragon
    int dragonCount;

    Monster *monsterArray; // array of monster
    int monsterCount;      // number of monster

    Clock PowerUpClock;

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
        disappear = false;

        E = nullptr;
        enemyCount = 0;

        bombsArray = new Bomb[0];
        bombCount = 0;

        BulletArray = new Bullet[0];
        bulletCount = 0;

        invadersArray = new Invaders[0];
        invadersCount = 0;

        dangerArray = new Danger[0];
        dangerCount = 0;

        fireArray = new Fire[0];
        fireCount = 0;

        powerUpArray = new PowerUp[0];
        powerUpCount = 0;

        DragonArray = new Dragon[0];
        dragonCount = 0;

        monsterArray = new Monster[0];
        monsterCount = 0;

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

    // void spawnBullet(Vector2f pos)
    // {
    //     Bullet b("img/PNG/Lasers/laserBlue01.png", 150, pos);
    //     addBullet(b);
    // }

    void spawnBullet(Vector2f pos, int direction)
    {
        if (direction == 0)
        {
            Bullet b("img/PNG/Lasers/laserBlue01.png", 150, pos);
            addBullet(b);

        }
        else
        {
            float angle = 360 / 7;

            for (int i = 0; i < 7; i++)
            {
                Bullet b("img/PNG/Lasers/laserBlue01.png", 150, pos, angle * i);
                b.getSprite().setRotation(angle * i + 90);
                addBullet(b);
            }
        }
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

    void addDragon(Dragon &d)
    {
        Dragon *temp = new Dragon[dragonCount + 1];
        for (int i = 0; i < dragonCount; i++)
        {
            temp[i] = DragonArray[i];
        }
        temp[dragonCount] = d;
        dragonCount++;
        DragonArray = temp;
    }

    void spawnDragon()
    {
        Dragon d("img/dragon.png");
        addDragon(d);
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

    void addDanger(Danger &d)
    {
        Danger *temp = new Danger[dangerCount + 1];
        for (int i = 0; i < dangerCount; i++)
        {
            temp[i] = dangerArray[i];
        }
        temp[dangerCount] = d;
        dangerCount++;
        dangerArray = temp;
    }

    void spawnDanger()
    {
        Danger d("img/PNG/Meteors/meteorBrown_med1.png", 150);

        addDanger(d);
    }

    void addFire(Fire &f)
    {
        Fire *temp = new Fire[fireCount + 1];
        for (int i = 0; i < fireCount; i++)
        {
            temp[i] = fireArray[i];
        }
        temp[fireCount] = f;

        fireCount++;

        fireArray = temp;
    }

    void spawnFire()
    {
        Fire f("img/PNG/Power-ups/bolt_bronze.png", 150);

        addFire(f);
    }

    void addPowerUp(PowerUp &p)
    {
        PowerUp *temp = new PowerUp[powerUpCount + 1];
        for (int i = 0; i < powerUpCount; i++)
        {
            temp[i] = powerUpArray[i];
        }
        temp[powerUpCount] = p;
        powerUpCount++;
        powerUpArray = temp;
    }

    void spawnPowerUp()
    {
        PowerUp p("img/PNG/Power-ups/bolt_gold.png", 150);

        addPowerUp(p);
    }

    void addMonster(Monster &m)
    {
        Monster *temp = new Monster[monsterCount + 1];
        for (int i = 0; i < monsterCount; i++)
        {
            temp[i] = monsterArray[i];
        }
        temp[monsterCount] = m;
        monsterCount++;
        monsterArray = temp;
    }

    void spawnMonster()
    {
        Monster m("img/monster1.png");

        addMonster(m);
    }

    void start_game(RenderWindow& window)
    {
        // srand(time(0));
        // RenderWindow window(VideoMode(780, 700), title);
        // // set fps
        // window.setFramerateLimit(60);

        Clock clock;
        
        
        float timer = 0;

        Clock deltaClock;
        double dt;

        double invaderSpawnTimer = 5;
        double bulletSpawnTimer = 1;
        double addonSpawnTimer = 10;
        
        // spawn monster randomly every 20 second
        double dragonSpawnTimer = 20;

        paused = false;
        disappear = false;

        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            dt = deltaClock.restart().asMicroseconds() / 1000000.0f;

            timer += time;
            invaderSpawnTimer -= dt;
            bulletSpawnTimer -= dt;

            addonSpawnTimer -= dt;
            dragonSpawnTimer -= dt;

            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close();          // close the game
            }

            // puase the game
            if (Keyboard::isKeyPressed(Keyboard::P))
            {
                // paused = !paused;
                disappear = !disappear;
            }
            if (Keyboard::isKeyPressed(Keyboard::Left) && !paused)  // If left key is pressed
                p->move("l", dt);                                   // Player will move to left
            if (Keyboard::isKeyPressed(Keyboard::Right) && !paused) // If right key is pressed
                p->move("r", dt);                                   // player will move to right
            if (Keyboard::isKeyPressed(Keyboard::Up) && !paused)    // If up key is pressed
                p->move("u", dt);                                   // playet will move upwards
            if (Keyboard::isKeyPressed(Keyboard::Down) && !paused)  // If down key is pressed
                p->move("d", dt);                                   // player will move downwards

            if (Keyboard::isKeyPressed(Keyboard::Space) && !paused)
            {
                if(bulletSpawnTimer <= 0){
                    spawnBullet(p->getPosition(),1);
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

            for (int i = 0; i < bulletCount; i++)
            {

                if (!paused)
                    BulletArray[i].move(dt);
                BulletArray[i].draw(window);

                // check if the bullet sprite intersects with enemy sprite and delete both
                for (int j = 0; j < invadersCount; j++)
                {
                    if(livesArray->intersect(BulletArray[i].getSprite(), invadersArray[j].getSprite()))    
                    {

                        scoreIncrease = true;
                        BulletArray[i].setDestroy();
                        invadersArray[j].setDestroy(true);
                        if (invadersArray[i].getDestroy())
                        {
                            invadersArray[i] = invadersArray[invadersCount - 1];
                            invadersCount--;
                        }
                    }
                }

                if (BulletArray[i].getPosition().y < 0)
                {
                    BulletArray[i] = BulletArray[bulletCount - 1];
                    bulletCount--;
                }
                
                if (BulletArray[i].getPosition().x < 0 || BulletArray[i].getPosition().x > 780 || BulletArray[i].getPosition().y > 700)
                {
                    BulletArray[i] = BulletArray[bulletCount - 1];
                    bulletCount--;
                    
                }
            }

            window.draw(p->sprite); // setting player on screen

            for (int i = 0; i < dangerCount; i++)
            {
                if (!disappear)
                {

                    if (!paused)
                        dangerArray[i].move(dt);
                    dangerArray[i].draw(window);
                }
            }

            for (int i = 0; i < livesCount; i++)
            {
                if (!disappear)
                {

                    if (!paused)
                        livesArray[i].move(dt);
                    livesArray[i].draw(window);
                }
            }

            for (int i = 0; i < fireCount; i++)
            {
                if (!disappear)
                {

                    if (!paused)
                        fireArray[i].move(dt);
                    fireArray[i].draw(window);
                }
            }

            for (int i = 0; i < powerUpCount; i++)
            {
                if (!disappear)
                {

                    if (!paused)
                        powerUpArray[i].move(dt);
                    powerUpArray[i].draw(window);
                }
            }
            

            // draw all bombs
            for (int i = 0; i < bombCount; i++)
            {
                if (!disappear)
                {
                    if (!paused)
                        bombsArray[i].move(dt);
                    bombsArray[i].draw(window);
                }

                for (int j = 0; j < bombCount; j++)
                {
                    if (livesArray->intersect(bombsArray[i].getSprite(), p->getSprite()))
                    {
                        cout << "intersect" << endl;

                        bombsArray[i].setDestroy();
                        p->setDestroy(true);
                        p->setLives(false);
                    }
                }
                // if bomb goes out of screen, delete it
                if (bombsArray[i].getPosition().y > 700)
                {
                    bombsArray[i] = bombsArray[bombCount - 1];
                    bombCount--;
                }
            }

            for (int i = 0; i < invadersCount; i++)
            {
                if (!disappear)
                {
                    if (!paused)
                        invadersArray[i].move(dt);
                    invadersArray[i].draw(window);
                }
            }

            for (int i = 0; i < dangerCount; i++)
            {
                if (livesArray->intersect(dangerArray[i].getSprite(), p->getSprite()))
                {
                    cout << "intersect" << endl;
                    // dangerArray[i].setDestroy();
                    p->setDestroy(true);
                    p->setLives(false);

                    dangerArray[i] = dangerArray[dangerCount - 1];
                    dangerCount--;
                }
            }



            if (paused)
            {


                

                Text text1, text2, text3, text4;
                Font font;
                font.loadFromFile("fonts/GAME_glm.ttf");
                text1.setFont(font);
                text1.setString("Game Paused");
                text1.setCharacterSize(50);
                text1.setFillColor(Color::White);
                text1.setPosition(200, 200);

                text2.setFont(font);
                text2.setString("Press P to resume");
                text2.setCharacterSize(30);
                text2.setFillColor(Color::White);
                text2.setPosition(250, 300);

                text3.setFont(font);
                text3.setString("Press Q to quit");
                text3.setCharacterSize(30);
                text3.setFillColor(Color::White);
                text3.setPosition(250, 350);
                
                text4.setFont(font);
                text4.setString("Press R to restart");
                text4.setCharacterSize(30);
                text4.setFillColor(Color::White);
                text4.setPosition(250, 400);



                window.draw(text1);
                window.draw(text2);
                window.draw(text3);
                window.draw(text4);
                window.display();

                continue;
            }

            // if(disappear){

            //     window.display();
            //     continue;
            // }

            // spawn invaders
            if (invaderSpawnTimer <= 0)
            {
                // choose random number between 1 and 3
                int random = rand() % 3 + 1;
                // if random is 1, spawn Alpha
                if (random == 1)
                {
                    Alpha I("img/enemy_1.png");

                    addInvader(I);
                }
                // if random is 2, spawn Beta
                else if (random == 2)
                {
                    Beta I("img/enemy_2.png");
                    addInvader(I);
                }
                // if random is 3, spawn Gamma
                else if (random == 3)
                {
                    Gamma I("img/enemy_3.png");
                    addInvader(I);
                }
                invaderSpawnTimer = 5;
            }

            for (int i = 0; i < dragonCount; i++)
            {
                if (disappear)
                {
                    if (!paused)
                        DragonArray[i].moved(dt);
                    DragonArray[i].draw(window);
                }
            }

            for(int i =0; i< monsterCount;i++){
                if(disappear){
                    if(!paused)
                        monsterArray[i].moved(dt);
                    monsterArray[i].draw(window);
                }
            }


            // check if player intersects with any of the invaders

            for (int i = 0; i < livesCount; i++)
            {
                if (livesArray->intersect(p->getSprite(), livesArray[i].getSprite()))
                {
                    livesArray[i].setDestroy();

                    p->setLives(true);

                    livesArray[i] = livesArray[livesCount - 1];
                    livesCount--;
                }
            }

            for(int i =0; i< powerUpCount;i++){
                if(livesArray->intersect(p->getSprite(), powerUpArray[i].getSprite())){
                    powerUpArray[i].setDestroy();
                    cout<<"intersect"<<endl;
                    p->PowerActive();

                    powerUpArray[i] = powerUpArray[powerUpCount - 1];
                    powerUpCount--;
                    
                    
                }
            }

            // loop through all the invaders
            for (int i = 0; i < invadersCount; i++)
            {
                // call onFrame
                invadersArray[i].onFrame(dt);
                // if invader.getdropBomb() == true
                if (invadersArray[i].getDropBomb())
                {
                    spawnBomb(invadersArray[i].getCenter());
                }
            }

            // spawn addons
            if (addonSpawnTimer <= 0)
            {
                // choose random number between 1 and 3
                int random = 4;
                // if random is 1, Lives
                if (random == 1 && true)
                {
                    spawnLives();
                }

                if (random == 2 && true)
                {
                    spawnDanger();
                }

                if (random == 3 && true)
                {
                    spawnFire();
                }

                if (random == 4 && true)
                {
                    spawnPowerUp();
                }

                // randomize spawn timer between 10 and 20
                addonSpawnTimer = rand() % 10 + 10;
            }
            if (scoreIncrease)
            {
                levelScore->update();
                scoreIncrease = false;
            }

            //spawn dragon
            if (dragonSpawnTimer <= 0 && disappear == false)
            {
                
                int random = rand() % 2 + 1;
                if (random == 1)
                {
                    spawnDragon();
                }
                else if (random == 2)
                {
                    spawnMonster();
                }
                disappear = !disappear;
                dragonSpawnTimer = 20;
            }


            p->render(window);
            levelScore->draw(window);

            window.display(); // Displying all the sprites
        }
    }

    ~Game()
    {
        delete p;
        delete[] invadersArray;
        delete[] BulletArray;
        delete[] bombsArray;
        delete[] livesArray;
        delete levelScore;
        delete[] dangerArray;
        delete[] fireArray;
        delete[] powerUpArray;
    }
};
