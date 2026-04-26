#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Game {
public:
    Game();
    virtual void startGame();
    virtual void endGame(bool win, int finalScore, RenderWindow& window, Font& font);
protected:
    string name;
    int score;
};
#endif // GAME_H
