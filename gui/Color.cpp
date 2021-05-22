#include "Color.h"

Color::Color(const std::string& s) {
    if (s == "red")
        *this = Color(255, 0, 0);
    else if (s == "green")
        *this = Color(0, 255, 0);
    else if (s == "blue")
        *this = Color(0, 0, 255);
    else
        *this = Color(0, 0, 0);
}
