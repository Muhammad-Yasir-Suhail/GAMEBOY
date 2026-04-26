#include "HangmanGame.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;
sf::Clock hClock;
HangmanGame::HangmanGame(RenderWindow& win, Font& f)
    : window(win), font(f), lives(8), guessedLetters(""), score(0) {
    if (!backgroundTexture.loadFromFile("Sprites/background1.png") ||!scoreBoxTexture.loadFromFile("Sprites/scorebox.png") || !livesBoxTexture.loadFromFile("Sprites/livesbox.png") ||
        !hintBoxTexture.loadFromFile("Sprites/hintbox.png") || !progBoxTexture.loadFromFile("Sprites/progressbox.png") || !winScreenTexture.loadFromFile("Sprites/winscreen.png") ||
        !logoTexture.loadFromFile("Sprites/hangmanlogo.png")) {
        cout << "Failed loading background/boxes sprites\n";
        return;
    }
    backgroundSprite.setTexture(backgroundTexture); //setting background
    backgroundSprite.setPosition(20, 0);
    backgroundSprite.setScale(1.0f, 1.0f);
    scoreBoxSprite.setTexture(scoreBoxTexture);  //Setting scorebox
    scoreBoxSprite.setPosition(18, 0);
    scoreBoxSprite.setScale(0.4f, 0.4f);
    livesBoxSprite.setTexture(livesBoxTexture);    //setting livebox
    livesBoxSprite.setPosition(500, 540);
    livesBoxSprite.setScale(0.5f, 0.5f);
    hintBoxSprite.setTexture(hintBoxTexture);      //setting hintbox
    hintBoxSprite.setPosition(0, 142);
    hintBoxSprite.setScale(0.7f, 0.7f);
    progressBoxSprite.setTexture(progBoxTexture);    //setting progressbox
    progressBoxSprite.setPosition(-10, 270);
    progressBoxSprite.setScale(1.0f, 1.0f);
    logoSprite.setTexture(logoTexture);      //setting intro
    logoSprite.setScale(0.8f, 0.6f);
    logoSprite.setPosition(120, 0);
    category.loadCategory();
    word = category.getWord();
    hint = category.getHint();
    for (int i = 0; i < 26; i++) {      //Sets key to true if pressed
        keyPressed[i] = false;
    }
    progress = string(Length(word), '_');
}
void HangmanGame::trackGuesses(char guess) {
    bool correct = false;
    int bonus = 0;
    for (int i = 0; i < Length(word); i++) {
        if (word[i] == guess && progress[i] == '_') {
            progress[i] = guess;
            correct = true;
            bonus++;
        }
    }
    if (correct) {
        score += (bonus > 1) ? (10 * bonus) : 5;
    }
    else {
        manageLives();
    }
    if (progress == word) {
        dispEndScr(true);
    }
}
void HangmanGame::drawHangman() {
    hangmanFigure.draw(8 - lives, window);
}

void HangmanGame::manageLives() {
    lives--;
    if (lives == 0) {
        sf::Clock pauseClock;          //To add effect at end of game
        while (pauseClock.getElapsedTime().asSeconds() < 2.0f) {
            window.clear(); 
            hangmanFigure.draw(8, window); 
            window.display(); 
        }
        dispEndScr(false); 
    }
}
void HangmanGame::dispEndScr(bool win) {
    Game game;
    game.endGame(win, score, window, font);
}
void HangmanGame::showLogo() {
    for (int i = 0; hClock.getElapsedTime().asSeconds() < 3; i++) {
        window.clear();
        window.draw(logoSprite);
        window.display();
    }
}
void HangmanGame::update() {
    Event event;
    for (; window.pollEvent(event); ) {
        if (event.type == Event::Closed)
            window.close();
        if (event.type == Event::KeyPressed) {
            if (event.key.code >= Keyboard::A && event.key.code <= Keyboard::Z) {
                char guess = 'A' + (event.key.code - Keyboard::A);    //converts in character from A to Z
                if (!keyPressed[guess - 'A']) {
                    trackGuesses(guess);
                    keyPressed[guess - 'A'] = true;     //to avoid pressing key again
                }
            }
        }
    }
    window.clear();
    window.draw(backgroundSprite);
    window.draw(scoreBoxSprite);
    window.draw(livesBoxSprite);
    window.draw(hintBoxSprite);
    window.draw(progressBoxSprite);
    drawHangman();
    Text scoreText("Score: " + stringConverter(score), font, 20);         //Updated score, lives, progress
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(30, 4);
    window.draw(scoreText);

    Text livesText("Lives: " + stringConverter(lives), font, 20);
    livesText.setFillColor(Color::White);
    livesText.setPosition(540, 557);
    window.draw(livesText);

    Text hintText("Hint: " + hint, font, 20);
    hintText.setFillColor(Color::White);
    hintText.setPosition(24, 158);
    window.draw(hintText);

    Text progressText("Progress: " + progress, font, 20);
    progressText.setFillColor(Color::White);
    progressText.setPosition(27, 300);
    window.draw(progressText);
}
