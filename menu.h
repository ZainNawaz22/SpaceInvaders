
#include "game.h"
class Menu
{
public:
    // add menu attributes here


    Menu()
    {

    }

    void display_menu()

    {
        RenderWindow window(VideoMode(500, 600), "OOP-Project, Spring-2023");
        Texture menu_texture;
        menu_texture.loadFromFile("img/background.png");
        Sprite menu_sprite(menu_texture);

        // Creating the "Start" button texture and sprite
        Texture start_button_texture;
        start_button_texture.loadFromFile("img/PNG/UI/buttonGreen.png");
        Sprite start_button_sprite(start_button_texture);
        start_button_sprite.setPosition(150, 200);


        // Main Menu Loop
        while (window.isOpen()){
            //handle events
            Event event;
            while(window.pollEvent(event))
            {
                switch (event.type)
                {
                case Event::Closed:
                    window.close();
                    break;
                case Event::MouseButtonPressed:
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        // if the mouse is clicked on the start button
                        if (start_button_sprite.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                        {
                            // start the game
                            Game g;
                            g.start_game();
                        }
                    }
                    break;
                }
            }

            // draw the menu
            window.clear();
            window.draw(menu_sprite);
            window.draw(start_button_sprite);
            window.display();
            


        }

        



        // Game g;
        // g.start_game();
        
        
    }
};
