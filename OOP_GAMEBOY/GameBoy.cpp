#include "GameBoy.h"
#include <iostream>

using namespace std;

GameBoy::GameBoy() : win(VideoMode(800, 600), "Gameboy"), screen(win), menu(screen), nameFlag(false) {}
bool GameBoy::loadAssets() {
    if (!logoTexture.loadFromFile("Sprites/gameboylogo.jpg") || !inputNameTexture.loadFromFile("Sprites/inputname.png") || !bgTexture.loadFromFile("Sprites/backgrnd.png") || !buttonTexture.loadFromFile("Sprites/scorebox.png")) {
        cout << "Failed to load textures of Gameboy\n";
        return false;
    }
    if (!font.loadFromFile("Sprites/Roboto.ttf")) {
        cout << "Failed to load font in Gameboy\n";
        return false;
    }
    logoSprite.setTexture(logoTexture);
    inputNameSprite.setTexture(inputNameTexture);
    bgSprite.setTexture(bgTexture);
    buttonSprite.setTexture(buttonTexture);
    return true;
}
void GameBoy::run() {
    while (win.isOpen()) {
        if (menu.getState() == MenuState::LogoScreen) {
            menu.logoScreen(win, logoSprite, clock);
        }
        else if (menu.getState() == MenuState::InputName) {
            menu.inputName(win, font, inputNameSprite, nameFlag);
        }
        else if (menu.getState() == MenuState::GameSelection) {
            menu.selectGame(win, font, bgSprite, buttonSprite);
        }
    }
}