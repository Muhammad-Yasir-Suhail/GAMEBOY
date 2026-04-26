#include "SnakeGame.h"
#include "utils.h"
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace sf;

SnakeGame::SnakeGame(RenderWindow& win)
    : win(win), size(1), sc(0), dx(0), dy(0) {
    win.setFramerateLimit(20);
    snake[0] = SnakeSegment(200, 200);
    spawnFood();

    if (!font.loadFromFile("Sprites/Roboto.ttf")) {
        exit(1);
    }

    txtScore.setFont(font);
    txtScore.setCharacterSize(24);
    txtScore.setFillColor(Color::White);
    txtScore.setPosition(10.f, 10.f);

    txtGameOver.setFont(font);
    txtGameOver.setCharacterSize(30);
    txtGameOver.setFillColor(Color::Red);
    txtGameOver.setPosition(300.f, 250.f);

    if (!texLogo.loadFromFile("Sprites/snake.png")) {
        exit(1);
    }
    sprLogo.setTexture(texLogo);
    sprLogo.setPosition(0, 0);
    sprLogo.setScale(1.2f, 1.2f);
}

void SnakeGame::input() {
    Event evt;
    while (win.pollEvent(evt)) {
        if (evt.type == Event::KeyPressed) {
            if ((evt.key.code == Keyboard::Up || evt.key.code == Keyboard::W) && dy == 0) {
                dx = 0; dy = -1;
            }
            else if ((evt.key.code == Keyboard::Down || evt.key.code == Keyboard::S) && dy == 0) {
                dx = 0; dy = 1;
            }
            else if ((evt.key.code == Keyboard::Left || evt.key.code == Keyboard::A) && dx == 0) {
                dx = -1; dy = 0;
            }
            else if ((evt.key.code == Keyboard::Right || evt.key.code == Keyboard::D) && dx == 0) {
                dx = 1; dy = 0;
            }
        }
    }
}

void SnakeGame::update() {
    if (dx != 0 || dy != 0) {
        Point head(snake[0].getPositionX() + dx * Grid::getBlockSize(),
            snake[0].getPositionY() + dy * Grid::getBlockSize());

        if (Grid::CheckBoundary(head)) {
            displayGameOver();
        }

        for (int i = 0; i < size; ++i) {
            if (snake[i].getPositionX() == head.getX() &&
                snake[i].getPositionY() == head.getY()) {
                displayGameOver();
            }
        }

        for (int i = size; i > 0; --i) {
            snake[i] = snake[i - 1];
        }
        snake[0].setPosition(head);

        if (head.getX() == food.getX() && head.getY() == food.getY()) {
            sc += 5;
            if (size < maxSize) {
                size++;
            }
            spawnFood();
        }
        txtScore.setString("Score: " + stringConverter(sc));
    }
}

void SnakeGame::drawSnake() {
    for (int i = 0; i < size; ++i) {
        RectangleShape rect(Vector2f(Grid::getBlockSize(), Grid::getBlockSize()));
        rect.setPosition(static_cast<float>(snake[i].getPositionX()),
            static_cast<float>(snake[i].getPositionY()));
        rect.setFillColor(Color::Green);
        win.draw(rect);
    }
}

void SnakeGame::drawFood() {
    RectangleShape rect(Vector2f(Grid::getBlockSize(), Grid::getBlockSize()));
    rect.setPosition(static_cast<float>(food.getX()), static_cast<float>(food.getY()));
    rect.setFillColor(Color::Red);
    win.draw(rect);
}

void SnakeGame::render() {
    win.clear();
    drawSnake();
    drawFood();
    win.draw(txtScore);
    win.display();
}

void SnakeGame::spawnFood() {
    food.setX((rand() % (Grid::getWidth() / Grid::getBlockSize())) * Grid::getBlockSize());
    food.setY((rand() % (Grid::getHeight() / Grid::getBlockSize())) * Grid::getBlockSize());
}

void SnakeGame::showLogoScreen() {
    Clock clk;
    while (clk.getElapsedTime().asSeconds() < 3) {
        win.clear();
        win.draw(sprLogo);
        win.display();
    }
}

void SnakeGame::displayGameOver() {
    txtGameOver.setString("Game Over\nScore: " + stringConverter(sc));
    win.clear();
    win.draw(txtGameOver);
    win.display();
    sleep(seconds(3));
    win.close();
}

void SnakeGame::run() {
    showLogoScreen();
    while (win.isOpen()) {
        input();
        update();
        render();
    }
}
