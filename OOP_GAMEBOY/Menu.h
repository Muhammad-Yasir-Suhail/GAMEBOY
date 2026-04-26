#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Screen.h"
using namespace std;
using namespace sf;
enum class MenuState { LogoScreen, 
    InputName,
    GameSelection
};
class Menu {
private:
    MenuState state;
    string playerName;
    Screen& screen;              // Reference to the Screen class for game launching
    Texture backgroundTexture;
    Texture buttonTexture;
public:
    Menu(Screen& launcher);
    void transition(MenuState nextState);
    MenuState getState() const;
    std::string getPlayerName() const;
    void setPlayerName(const string& name);
    void logoScreen(RenderWindow& win, Sprite& logoSprite, Clock& clock);
    void inputName(RenderWindow& win, Font& font, Sprite& inputSprite, bool& nameFlag);
    void selectGame(RenderWindow& win, Font& font, Sprite& bgSprite, Sprite& buttonSprite);
    Texture& getBackgroundTexture();
    Texture& getButtonTexture();
};

#endif
