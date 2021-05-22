#include <screens/ScreensManager.h>
#include <screens/GameScreen.h>


#ifdef debug
#include <iostream>
using std::cout;
using std::endl;
#endif

int main(int argc, char* argv[]) {
#ifdef debug
    cout << "[OK]. Ну че [CENSORED] рот - погнали [CENSORED]!" << std::endl;
#endif

    ScreensManager::getInstance().setScreen(std::make_shared<GameScreen>());

    while(true) {
        ScreensManager::getInstance().Tick();
    }

    /*std::shared_ptr<MapEditor> editor = std::make_shared<MapEditor>();
    editor->setGUI(std::make_shared<SfmlGUI>());
    editor->loop();*/

    return 0;
}