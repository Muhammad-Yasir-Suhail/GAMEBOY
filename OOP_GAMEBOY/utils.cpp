#include "utils.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int Length(string str) {
    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        ++len;
    }
    return len;
}
string stringConverter(int num) {
    if (num == 0) {
        return "0";
    }
    string res = "";
    bool isNegative = num < 0;
    if (isNegative) {
        num = -num;
    }
    while (num > 0) {
        res += (num % 10) + '0';
        num /= 10;
    }
    if (isNegative) {
        res += '-';
    }
    string reversed = "";
    for (int i = Length(res) - 1; i >= 0; --i) {
        reversed += res[i];
    }
    return reversed;
}

void fitSpriteToScreen(Sprite& sprite, const RenderWindow& window) {
    Vector2u winSize = window.getSize();
    Vector2u texSize = sprite.getTexture()->getSize();

    float scaleX = static_cast<float>(winSize.x) / texSize.x;
    float scaleY = static_cast<float>(winSize.y) / texSize.y;

    float scale = scaleX < scaleY ? scaleX : scaleY;
    sprite.setScale(scale, scale);

    float offsetX = (winSize.x - sprite.getGlobalBounds().width) / 2.f;
    float offsetY = (winSize.y - sprite.getGlobalBounds().height) / 2.f;

    sprite.setPosition(offsetX, offsetY);
}
void copy(char* dest, const char* src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        ++i;
    }
}
