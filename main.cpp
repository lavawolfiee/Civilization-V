#include "Game.h"
#include "gui/SfmlGUI.h"
#include "maps/DuelMapGenerator.h"


#ifdef debug
#include <iostream>
using std::cout;
using std::endl;
#endif

signed main() {
#ifdef debug
    cout << "[OK]. Ну че ебанный рот - погнали нахуй!" << std::endl;
#endif
    DuelMapGenerator mapGenerator;
    Game game(new SfmlGUI, mapGenerator.generateMap());
    game.loop();

    return 0;
}