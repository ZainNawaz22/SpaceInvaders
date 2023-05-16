#include<iostream>
#include <fstream>
#include<string>
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

        int getScore(){
            return score;
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

        void saveScore(){
            // append score to file
            ofstream file;
            file.open("HighScore", ios::app);
            file << score << endl;
            file.close();
        }

        void loadScore(){
            // load score from file
            ifstream file;
            string name;
            cout << "Enter filename: ";
            cin >> name;
            file.open(name);
            string line;
            while(getline(file, line)){
                cout << line << endl;
            }
            file.close();
        }

        // game Over Score Display
        void gameOver(RenderWindow &window, bool gameover){
            Font font;
            font.loadFromFile("fonts/GAME_glm.ttf");
            Text text;
            text.setFont(font);
            // display the score
            text.setString("Score: " + to_string(getScore()));
            text.setCharacterSize(24);
            text.setFillColor(Color::White);
            text.setPosition(300, 400);
            window.draw(text);
            window.display();
        }



};
