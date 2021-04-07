#include "Game.h"
#include "gui/SfmlGUI.h"
#include "maps/StandardMapGenerator.h"
#include "MapEditor.h"


#ifdef debug
#include <iostream>
using std::cout;
using std::endl;
#endif

int main(int argc, char* argv[]) {
#ifdef debug
    cout << "[OK]. Ну че [CENSORED] рот - погнали [CENSORED]!" << std::endl;
#endif
    StandardMapGenerator mapGenerator;
    std::shared_ptr<Game> game = std::make_shared<Game>();
    game->setGUI(std::make_shared<SfmlGUI>());
    game->setMap(mapGenerator.generateMap());
    game->loop();
    /*std::shared_ptr<MapEditor> editor = std::make_shared<MapEditor>();
    editor->setGUI(std::make_shared<SfmlGUI>());
    editor->loop();*/

    return 0;
}