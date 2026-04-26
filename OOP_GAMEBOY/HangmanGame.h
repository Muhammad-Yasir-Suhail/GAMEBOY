#ifndef HANGMANGAME_H
#define HANGMANGAME_H
#include <string>
#include "Category.h"
#include "HangmanFigure.h"
#include "Game.h"
#include "utils.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;
class HangmanGame: public Game {
private:
    Category category;            //Composing category
    HangmanFigure hangmanFigure;  //Composing hangmanFigure
    string word;
    string hint;
    string progress;
    int lives;
    int score;
    bool keyPressed[26];
    string guessedLetters;
    RenderWindow& window;
    Font font;
    Texture backgroundTexture, scoreBoxTexture, livesBoxTexture, hintBoxTexture, progBoxTexture, logoTexture, winScreenTexture;
    Sprite backgroundSprite, scoreBoxSprite, livesBoxSprite, hintBoxSprite, progressBoxSprite, logoSprite;
    
    void trackGuesses(char guess);
    void drawHangman();
    void manageLives();
    void dispEndScr(bool win);
    void showLogo();
   
    
public:
    HangmanGame(RenderWindow& win, Font& f);
    void startGame() {
        showLogo();
    }
    void update();
};
#endif
