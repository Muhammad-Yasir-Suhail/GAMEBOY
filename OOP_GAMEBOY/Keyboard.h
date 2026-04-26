#pragma once

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include<SFML/Graphics.hpp>
using namespace sf;

class KeyBoard
{
	RectangleShape keys[26];
	Font font;
public:
    KeyBoard() {
       
        for (int i = 0; i < 26; ++i) {
            keys[i].setSize(sf::Vector2f(40, 40));
            keys[i].setFillColor(sf::Color::White);
     
            if (i == 0) keys[i].setPosition(50, 400);
            else if (i == 1) keys[i].setPosition(95, 400);
            else if (i == 2) keys[i].setPosition(140, 400);
            else if (i == 3) keys[i].setPosition(185, 400);                             //Setting the keys
            else if (i == 4) keys[i].setPosition(230, 400);
            else if (i == 5) keys[i].setPosition(275, 400);
            else if (i == 6) keys[i].setPosition(320, 400);
            else if (i == 7) keys[i].setPosition(365, 400);
            else if (i == 8) keys[i].setPosition(410, 400);
            else if (i == 9) keys[i].setPosition(455, 400); 
            else if (i == 10) keys[i].setPosition(50, 445);
            else if (i == 11) keys[i].setPosition(95, 445);
            else if (i == 12) keys[i].setPosition(140, 445);
            else if (i == 13) keys[i].setPosition(185, 445);
            else if (i == 14) keys[i].setPosition(230, 445);
            else if (i == 15) keys[i].setPosition(275, 445);
            else if (i == 16) keys[i].setPosition(320, 445);
            else if (i == 17) keys[i].setPosition(365, 445);
            else if (i == 18) keys[i].setPosition(410, 445);
            else if (i == 19) keys[i].setPosition(455, 445);
            else if (i == 20) keys[i].setPosition(50, 490); 
            else if (i == 21) keys[i].setPosition(95, 490);
            else if (i == 22) keys[i].setPosition(140, 490);
            else if (i == 23) keys[i].setPosition(185, 490);
            else if (i == 24) keys[i].setPosition(230, 490);
            else if (i == 25) keys[i].setPosition(275, 490);
            
        }
        font.loadFromFile("Sprites/Roboto.ttf"); 
    }

    void draw(sf::RenderWindow& window);

    //void updateKeyColor(char c, Color color);
    void updateColors(char* guess,char* target);
};

#endif