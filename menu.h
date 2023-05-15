
#include "game.h"
class Menu
{
public:
    // add menu attributes here


    Menu()
    {

    }

    //make a menu function that displays the menu

void display_menu() {
    // ...

    // Create the window
    RenderWindow window(VideoMode(780, 700), "OOP-Project, Spring-2023");
    window.setFramerateLimit(60);
    // Load background image
    Texture texture;
    texture.loadFromFile("img/background_1.png");
    Sprite menuBackground(texture);


    // Load font and create menu texts
    Font font;
    font.loadFromFile("fonts/GAME_glm.ttf");
    Text text1, text2, text3, text4;
    text1.setFont(font);
    text1.setString("Start");
    text1.setCharacterSize(24);
    text1.setFillColor(Color::White);
    text1.setPosition(155, 195);

    text2.setFont(font);
    text2.setString("Instructions");
    text2.setCharacterSize(24);
    text2.setFillColor(Color::Black);
    text2.setPosition(155, 245);

    text3.setFont(font);
    text3.setString("High Scores");
    text3.setCharacterSize(24);
    text3.setFillColor(Color::Black);
    text3.setPosition(155, 295);

    text4.setFont(font);
    text4.setString("Exit");
    text4.setCharacterSize(24);
    text4.setFillColor(Color::Black);
    text4.setPosition(155, 345);

    // Main Menu Loop
    while (window.isOpen()) {
        // Handle events
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::H) {
                        // Display high score menu
                        // display_high_score_menu(window);
                    } else if (event.key.code == Keyboard::I) {
                        // Display instructions menu
                         display_instructions_menu(window);
                    } else if (event.key.code == Keyboard::Enter) {
                        // Start the game
                        Game g;
                        g.start_game(window);
                    }
                    else if(event.key.code == Keyboard::P){
                        //Pause the game
                        //display_pause_menu(window);
                    }


                     else if (event.key.code == Keyboard::Escape) {
                        // Exit the game
                        window.close();
                    }
                    break;
            }
        }

        // Clear the window
        window.clear();

        // Draw menu texts
        window.draw(menuBackground);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);

        // Display the window
        window.display();
    }
}



void display_instructions_menu(RenderWindow& window) {
    // ...

    // Load background image
    Texture texture;
    texture.loadFromFile("img/background.jpg");
    Sprite menuBackground(texture);

    // Load font and create menu texts
    Font font;
    font.loadFromFile("fonts/GAME_glm.ttf");
    Text text1, text2, text3, text4;
    text1.setFont(font);
    text1.setString("Instructions");
    text1.setCharacterSize(24);
    text1.setFillColor(Color::White);
    text1.setPosition(155, 195);

    text2.setFont(font);
    text2.setString("Use the arrow keys to move the snake");
    text2.setCharacterSize(24);
    text2.setFillColor(Color::Black);
    text2.setPosition(155, 245);

    text3.setFont(font);
    text3.setString("Press P to pause the game");
    text3.setCharacterSize(24);
    text3.setFillColor(Color::Black);
    text3.setPosition(155, 295);

    text4.setFont(font);
    text4.setString("Press Esc to exit the game");
    text4.setCharacterSize(24);
    text4.setFillColor(Color::Black);
    text4.setPosition(155, 345);


    // ...

    // Instructions Menu Loop
    bool instructionsOpen = true; // Flag to control the instructions menu loop
    while (instructionsOpen && window.isOpen()) {
        // Handle events
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape) {
                        
                        instructionsOpen = false;
                    }
                    break;
            }
        }

        // Clear the window
        window.clear();

        // Draw menu texts
        window.draw(menuBackground);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);

        // Display the window
        window.display();
    }
}

// function for pause menu
void display_pause_menu(RenderWindow& window) {

    cout<<"pause menu"<<endl;

    // Load font and create menu texts
    Font font;
    font.loadFromFile("fonts/GAME_glm.ttf");
    Text text1, text2, text3, text4;
    text1.setFont(font);
    text1.setString("Pause Menu");
    text1.setCharacterSize(24);
    text1.setFillColor(Color::White);
    text1.setPosition(155, 195);

    text2.setFont(font);
    text2.setString("Press R to resume the game");
    text2.setCharacterSize(24);
    text2.setFillColor(Color::Black);
    text2.setPosition(155, 245);

    text3.setFont(font);
    text3.setString("Press Esc to exit the game");
    text3.setCharacterSize(24);
    text3.setFillColor(Color::Black);
    text3.setPosition(155, 295);

    text4.setFont(font);
    text4.setString("Press H to view high scores");
    text4.setCharacterSize(24);
    text4.setFillColor(Color::Black);
    text4.setPosition(155, 345);


    // ...

    window.clear();

    // Draw menu texts
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);

    // Display the window
    window.display();

    // Pause Menu Loop
    bool pauseOpen = true; // Flag to control the pause menu loop
    while (pauseOpen && window.isOpen()) {
        // Handle events
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::R) {
                        // Resume the game
                        pauseOpen = false;
                    } else if (event.key.code == Keyboard::H) {
                        // Display high score menu
                        // display_high_score_menu(window);
                    } else if (event.key.code == Keyboard::Escape) {
                        // Exit the game
                        window.close();
                    }
                    break;
            }
        }
    }



};

};
