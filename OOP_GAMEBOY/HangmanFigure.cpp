#include "HangmanFigure.h"
#include <string>
using namespace std;
using namespace sf;
HangmanFigure::HangmanFigure() : stage(0) {}
void HangmanFigure::draw(int stage, RenderWindow& window) {
    Texture texture;
    Sprite sprite;
    string fName = "Sprites/HangMan" + stringConverter(stage) + ".png";
    if (texture.loadFromFile(fName)) {
        sprite.setTexture(texture);
        sprite.setPosition(115, 2);
        window.draw(sprite);
    }
}
