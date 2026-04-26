#include "Screen.h"
#include <iostream>
using namespace sf;
using namespace std;

Screen::Screen(RenderWindow& win) : win(win) {}

void Screen::launchGame(const string& gameName) {
    if (gameName == "Hangman") {
        Font font;
        if (!font.loadFromFile("Sprites/Roboto.ttf")) {
            cout << "Failed to load font in Screen!" << endl;
            return;
        }
        HangmanGame hangmanGame(win, font);
        hangmanGame.startGame();

        while (win.isOpen()) {
            hangmanGame.update();
            win.display();
        }
    }
    else if (gameName == "Snake") {
        SnakeGame snakeGame(win);
        snakeGame.run();
    }
    else if (gameName == "Wordle") {
        WordleGame wordleGame;
        wordleGame.play(win);
    }
    else {
        cout << "Didn't find it\n";
    }
}
