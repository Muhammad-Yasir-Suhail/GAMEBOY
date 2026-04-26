#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>
#include "HangmanGame.h"
#include "SnakeGame.h"
#include "WordleGame.h"
using namespace sf;
using namespace std;

class Screen {
private:
    RenderWindow& win;
public:
    Screen(RenderWindow& win);
    void launchGame(const string& gameName);
};
#endif 
