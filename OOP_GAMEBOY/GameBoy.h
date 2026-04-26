#ifndef GAMEBOY_H
#define GAMEBOY_H
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Screen.h"
using namespace sf;
class GameBoy {
private:
    Screen screen;
    Menu menu;
    RenderWindow win;
    Texture logoTexture, inputNameTexture, bgTexture, buttonTexture;
    Font font;
    Sprite logoSprite, inputNameSprite, bgSprite, buttonSprite;
    Clock clock;
    bool nameFlag;
public:
    GameBoy();
    bool loadAssets();
    void run();
};

#endif
