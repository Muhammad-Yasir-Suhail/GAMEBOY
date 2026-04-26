#ifndef WORDGAME_H
#define WORDGAME_H
#include "Letter.h"
#include "Keyboard.h"
#include "WordDictionary.h"
#include "Word.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include<fstream>
using namespace std;

class WordleGame
{
	
    Dictionary dictionary;
    Word target;
    Word current;
	KeyBoard virtualKeyBoard;
	static const int lives = 5;
    Font font;
    Text text;
	int tries;
    RectangleShape grid[lives][5];
  
public:

  

    void initializeGrid();
    void drawGrid(RenderWindow& window);
    

    WordleGame() : tries(0) {
        char randomWord[6];
        dictionary.getRandomWord(randomWord);
        target.setWord(randomWord);
        initializeGrid();
        if (!font.loadFromFile("Sprites/Roboto.ttf")) { // Load a font
            std::cerr << "Error loading font" << std::endl;
        }
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
    }

   


    void updateGrid();

    void updateGridColors();

    void play(RenderWindow& window);

};

#endif