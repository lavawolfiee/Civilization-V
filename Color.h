#ifndef CIVILIZATION_V_COLOR_H
#define CIVILIZATION_V_COLOR_H

#include <string>

class Color {
public:
    unsigned int r, g, b, a;

    Color(unsigned int r = 0, unsigned int g = 0, unsigned int b = 0, unsigned int a = 255): r(r), g(g), b(b), a(a) {
    }

    Color(const std::string& s);
};


#endif //CIVILIZATION_V_COLOR_H
