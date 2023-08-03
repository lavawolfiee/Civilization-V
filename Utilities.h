#ifndef CIVILIZATION_V_UTILITIES_H
#define CIVILIZATION_V_UTILITIES_H

#include <iostream>

struct Point {
    int x, y;

    explicit Point(int x = 0, int y = 0) : x(x), y(y) {};

    Point(std::initializer_list<int> l) : x(*l.begin()), y(*std::next(l.begin())) {};
};

bool operator==(const Point& l, const Point& r);
bool operator<(const Point& l, const Point& r);

namespace std {
    template<>
    struct hash<Point> {
        size_t operator()(const Point& r) const noexcept {
            return std::hash<int>()(r.x) ^ (std::hash<int>()(r.y) << 1);
        }
    };

    template<typename T>
    struct hash< std::pair<T, T> > {
        size_t operator()(const std::pair<T, T>& r) const noexcept {
            return std::hash<T>()(r.first) ^ (std::hash<T>()(r.second) << 1);
        }
    };
}

unsigned int hexDistance(Point p1, Point p2);

class Quit: public std::exception {};

#endif //CIVILIZATION_V_UTILITIES_H
