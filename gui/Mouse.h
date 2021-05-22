#ifndef CIVILIZATION_V_MOUSE_H
#define CIVILIZATION_V_MOUSE_H


class Mouse {
public:
    int x;
    int y;
    bool pressed = false;
    int pressX = 0;
    int pressY = 0;

    Mouse(int x = 0, int y = 0): x(x), y(y) {}
};


#endif //CIVILIZATION_V_MOUSE_H
