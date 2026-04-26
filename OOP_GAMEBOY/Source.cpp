#include "GameBoy.h"
int main() {
    GameBoy game;
    if (!game.loadAssets()) {
        cout << "Assets failed to load\n";
        return -1; 
    }
    game.run();
    return 0;
}
