#ifndef CIVILIZATION_V_MAINMENU_H
#define CIVILIZATION_V_MAINMENU_H

#include "Screen.h"
#include "ScreensManager.h"
#include "GameScreen.h"
#include "Utilities.h"

class MainMenu : public Screen {
public:

    MainMenu();

    void recreateUI() override;
    void Tick(unsigned long long) override;

};


#endif //CIVILIZATION_V_MAINMENU_H
