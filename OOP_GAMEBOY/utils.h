#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
int Length(string str);
string stringConverter(int value);
void fitSpriteToScreen(sf::Sprite& sprite, const sf::RenderWindow& window);
void copy(char* destination, const char* source);
#endif
