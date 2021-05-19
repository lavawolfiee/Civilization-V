#ifndef CIVILIZATION_V_UTILITIES_H
#define CIVILIZATION_V_UTILITIES_H

struct Point {
    int x, y;

    explicit Point(int x = 0, int y = 0) : x(x), y(y) {};
    Point(std::initializer_list<int> l) : x(*l.begin()), y(*std::next(l.begin())) {};

    bool operator==(const Point& r) const {
        return (x == r.x) && (y == r.y);
    }
};

/*bool operator==(const Point& l, const Point& r);

bool operator==(const Point& l, const Point& r) {
    return (l.x == r.x) && (l.y == r.y);
}*/

namespace std {
    template<>
    struct hash<Point > {
        size_t operator()(const Point& r) const noexcept {
            return std::hash<int>()(r.x) ^ (std::hash<int>()(r.y) << 1);
        }
    };
}

#endif //CIVILIZATION_V_UTILITIES_H
