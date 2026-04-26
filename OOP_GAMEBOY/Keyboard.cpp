#include "KeyBoard.h"


void KeyBoard::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 26; ++i) {
        window.draw(keys[i]);

        sf::Text letterText;
        letterText.setFont(font);
        letterText.setString(static_cast<char>('A' + i));
        letterText.setCharacterSize(20);
        letterText.setFillColor(sf::Color::Black);
        letterText.setPosition(keys[i].getPosition().x + 10, keys[i].getPosition().y + 5);
        window.draw(letterText);
    }
}


//void KeyBoard::updateKeyColor(char c, Color color) {
//    if (c >= 'A' && c <= 'Z') {
//        keys[c - 'A'].setFillColor(color);
//    }
//}



void KeyBoard::updateColors(char* guess, char* target) {
    for (int i = 0; i < 5; ++i) {
        if (guess[i] == target[i]) {
         

            char currentLetter = guess[i];                    //getting the index and changing its colour
            int index = currentLetter - 'a'; 
            keys[index].setFillColor(sf::Color::Green); 
        }
        else {
            bool found = false;
            for (int j = 0; j < 5; ++j) {
                if (target[j] == guess[i]) {
                    found = true;
                    break;
                }
            }
            if (found) {
                

                char currentLetter = guess[i];
                int index = currentLetter - 'a'; 
                keys[index].setFillColor(sf::Color::Yellow); 
            }
            else {
            

                char currentLetter = guess[i]; 
                int index = currentLetter - 'a'; 
                keys[index].setFillColor(sf::Color::Red); 
            }
        }
    }
}