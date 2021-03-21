#include "Game.h"
#include "SfmlGUI.h"
#include "maps/DuelMapGenerator.h"

int main() {
    DuelMapGenerator mapGenerator;
    Game game(new SfmlGUI, mapGenerator.generateMap());
    game.loop();

    return 0;
}