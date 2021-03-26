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
    cout << "[OK]. Ну че [CENSORED] рот - погнали [CENSORED]!" << std::endl;
#endif
    DuelMapGenerator mapGenerator;
    std::shared_ptr<Game> game = std::make_shared<Game>();
    game->setGUI(std::make_shared<SfmlGUI>());
    game->setMap(mapGenerator.generateMap());
    game->loop();

    return 0;
}