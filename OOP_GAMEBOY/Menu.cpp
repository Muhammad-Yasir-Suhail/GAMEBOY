#include "Menu.h"
#include <iostream>
using namespace std;
using namespace sf;
Menu::Menu(Screen& launcher) : state(MenuState::LogoScreen), playerName(""), screen(launcher) {}
void Menu::transition(MenuState nextState) {
    state = nextState;
}
MenuState Menu::getState() const {
    return state;
}
string Menu::getPlayerName() const {
    return playerName;
}
void Menu::setPlayerName(const string& name) {
    playerName = name;
}
void Menu::logoScreen(RenderWindow& window, Sprite& logoSprite, Clock& clock) {
    if (clock.getElapsedTime().asSeconds() < 3) {
        window.clear();
        window.draw(logoSprite);
        window.display();
    }
    else {
        transition(MenuState::InputName);
    }
}
void Menu::inputName(RenderWindow& window, Font& font, Sprite& inputSprite, bool& isNameEntered) {
    static char enteredName[100] = "";
    static int length = 0;
    Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(34);
    inputText.setFillColor(Color::Black);
    inputText.setPosition(260, 320);
    inputText.setString(string(enteredName, length));
    inputSprite.setScale(0.8f, 0.92f);
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }
        else if (event.type == Event::TextEntered) {
            if (event.text.unicode < 128) {
                if (event.text.unicode == 13) {
                    isNameEntered = true;
                    playerName = string(enteredName, length);
                    transition(MenuState::GameSelection);
                }
                else if (event.text.unicode == 8) {
                    if (length > 0) {
                        enteredName[--length] = '\0';
                    }
                }
                else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                    if (length < 99) {
                        enteredName[length++] = static_cast<char>(event.text.unicode);
                        enteredName[length] = '\0';
                    }
                }
            }
        }
    }
    window.clear();
    window.draw(inputSprite);
    window.draw(inputText);
    window.display();
}
void Menu::selectGame(RenderWindow& window, Font& font, Sprite& backgroundSprite, Sprite& buttonSprite) {
    Sprite hangmanButton(buttonSprite);
    hangmanButton.setPosition(250, 150);
  //  hangmanButton.setScale(0.8f, 0.8f);
    Text hangmanText;
    hangmanText.setFont(font);
    hangmanText.setString("Hangman");
    hangmanText.setCharacterSize(28);
    hangmanText.setFillColor(Color::White);
    hangmanText.setPosition(270, 165);
    Sprite snakeButton(buttonSprite);
    snakeButton.setPosition(250, 250);

    Text snakeText;
    snakeText.setFont(font);
    snakeText.setString("Snake");
    snakeText.setCharacterSize(28);
    snakeText.setFillColor(Color::White);
    snakeText.setPosition(270, 265);

    Sprite wordleButton(buttonSprite);
    wordleButton.setPosition(250, 350);
    Text wordleText;
    wordleText.setFont(font);
    wordleText.setString("Wordle");
    wordleText.setCharacterSize(28);
    wordleText.setFillColor(Color::White);
    wordleText.setPosition(270, 365);
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }
        else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            sf::Vector2i mousePos = Mouse::getPosition(window);

            if (mousePos.x >= 250 && mousePos.x <= 450 && mousePos.y >= 150 && mousePos.y <= 200) {
                screen.launchGame("Hangman");
                return;
            }
            if (mousePos.x >= 250 && mousePos.x <= 450 && mousePos.y >= 250 && mousePos.y <= 300) {
                screen.launchGame("Snake");
                return;
            }
            if (mousePos.x >= 250 && mousePos.x <= 450 && mousePos.y >= 350 && mousePos.y <= 400) {
                screen.launchGame("Wordle");
                return;
            }
        }
    }
    window.clear();
    window.draw(backgroundSprite);
    window.draw(hangmanButton);
    window.draw(hangmanText);
    window.draw(snakeButton);
    window.draw(snakeText);
    window.draw(wordleButton);
    window.draw(wordleText);
    window.display();
}
Texture& Menu::getBackgroundTexture() {
    return backgroundTexture;
}
Texture& Menu::getButtonTexture() {
    return buttonTexture;
}