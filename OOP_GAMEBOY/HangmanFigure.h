#ifndef HANGMANFIGURE_H
#define HANGMANFIGURE_H
#include "utils.h"
#include <SFML/Graphics.hpp>
class HangmanFigure {
    int stage;
public:
    HangmanFigure();
    void draw(int stage, sf::RenderWindow& window);
};
#endif
