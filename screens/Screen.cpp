#include "Screen.h"

void Screen::setGui(std::shared_ptr <GUI> gui) {
    this->gui = std::move(gui);
    recreateUI();
}
