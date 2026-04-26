#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Point.h"
#include "SnakeSegment.h"
using namespace sf;
class SnakeGame {
private:
    RenderWindow& win;
    Font font;
    Text txtScore, txtGameOver;
    Texture texLogo;
    Sprite sprLogo;
    static const int maxSize = 100;
    SnakeSegment snake[maxSize];
    Point food;
    int size, sc, dx, dy;
    void input();
    void update();
    void render();
    void drawSnake();
    void drawFood();
    void spawnFood();
    void showLogoScreen();
    void displayGameOver();
public:
    SnakeGame(RenderWindow& win);
    void run();
};
#endif