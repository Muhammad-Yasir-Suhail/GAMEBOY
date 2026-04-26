#include "WordleGame.h"
void WordleGame::initializeGrid() {
    int startingPos = 100;
    int spaces = 60;
    for (int i = 0; i < lives; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j].setSize(sf::Vector2f(50, 50));
            grid[i][j].setPosition(startingPos + j * spaces, startingPos + i * spaces);
            grid[i][j].setFillColor(sf::Color::White);
            grid[i][j].setOutlineThickness(2);
            grid[i][j].setOutlineColor(sf::Color::Black);
        }
    }
}
void WordleGame::drawGrid(sf::RenderWindow& window) {
    for (int i = 0; i < tries; ++i) { 
        for (int j = 0; j < 5; ++j) {
            window.draw(grid[i][j]); 
            
            ///checking the row and then drawing
            if (i == tries - 1) { 
                char letter = current.getWord()[j]; 
                text.setString(letter); 
                text.setPosition(grid[i][j].getPosition().x + 10, grid[i][j].getPosition().y + 5);
                window.draw(text); 
            }
        }
    }
}


void WordleGame::updateGrid() {
    for (int j = 0; j < 5; ++j) {
        char letter = current.getWord()[j];                              //get the guessed letters
        grid[tries][j].setFillColor(sf::Color::Cyan); 
       
    }
}

void WordleGame::updateGridColors() {
    const char* guess = current.getWord();
    const char* targetWord = target.getWord();
    bool targetUsed[5] = { false };                          //check which letters are correct

   
    for (int i = 0; i < 5; ++i) {
        if (guess[i] == targetWord[i]) {
            grid[tries][i].setFillColor(sf::Color::Green); 
            targetUsed[i] = true;
        }
    }

  
    for (int i = 0; i < 5; ++i) {
        if (grid[tries][i].getFillColor() != sf::Color::Green) { 
            bool found = false;
            for (int j = 0; j < 5; ++j) {
                if (guess[i] == targetWord[j] && !targetUsed[j]) {
                    found = true;
                    targetUsed[j] = true;
                    break;
                }
            }
            if (found) {
                grid[tries][i].setFillColor(sf::Color::Yellow);
            }
            else {
                grid[tries][i].setFillColor(sf::Color::Red);
            }
        }
    }
}

bool isAlphabet(char ch) {
    
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return 1;
    else
        return 0;
}
char LowerCaseConverter(char ch){
    if (ch >= 'A' && ch <= 'Z') {
        
        return ch + 32;
    }
    
    return ch;
}

void WordleGame::play(RenderWindow& window) {

    while (window.isOpen() && tries < lives) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 && isAlphabet(event.text.unicode)) {
                    char letter = LowerCaseConverter(static_cast<char>(event.text.unicode));
                    current.addLetter(letter);
                    if (current.isComplete()) {
                        virtualKeyBoard.updateColors(current.getWord(), target.getWord());
                        updateGrid();
                        updateGridColors();
                        virtualKeyBoard.updateColors(current.getWord(), target.getWord());
                        tries++;
                        current.reset();
                    }
                }
            }
        }

        window.clear();
        drawGrid(window);
        virtualKeyBoard.draw(window);
        window.display();
    }
}