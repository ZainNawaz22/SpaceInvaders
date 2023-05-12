#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Score{
    public:
        int score;
        Font font;
        Text text;
    
        Score(){
            score = 0;
            font.loadFromFile("fonts/GAME_glm.ttf");
           
            text.setFont(font);
            text.setString("Score: " + to_string(score));
            text.setCharacterSize(24);
            text.setFillColor(Color::White);
            text.setPosition(10, 10);
        }

        void draw(RenderWindow &window){
            window.draw(text);
        }

        void update(){
            score+=10;
            text.setString("Score: " + to_string(score));
        }

        void update(int increase){
            score+=increase;
            text.setString("Score: " + to_string(score));
        }

};
