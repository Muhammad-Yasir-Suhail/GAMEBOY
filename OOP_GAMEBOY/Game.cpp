#include "Game.h"
#include "utils.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
Game::Game() : name("Hangman"), score(0) {}

void Game::startGame() {
    cout << "Game Started\n";
}

void Game::endGame(bool win, int finalScore, RenderWindow& window, Font& font) {
    Texture endSTexture, fSTexture;
    string screenFile = win ? "Sprites/winscreen.png" : "Sprites/losescreen.png";
    if (!endSTexture.loadFromFile(screenFile) || !fSTexture.loadFromFile("Sprites/finalscorebox.png")) {
        cout << "Failed loading end screen textures!\n";
        return;
    }
    Sprite endSprite(endSTexture);
    Sprite finalSprite(fSTexture);
    if (win) {
        endSprite.setPosition(100, 30);
    }
    else {
        endSprite.setPosition(100, 250);
        endSprite.setScale(1.0f, 1.0f);
    }

    finalSprite.setPosition(140, 403);
    finalSprite.setScale(1.1f, 0.5f);
    window.clear();
    window.draw(endSprite);
    window.draw(finalSprite);
    Text scoreText("Final Score: " + stringConverter(finalScore), font, 30);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(220, 420);
    window.draw(scoreText);
    window.display();
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
    }
}
