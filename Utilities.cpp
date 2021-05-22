#include "Utilities.h"

bool operator==(const Point& l, const Point& r) {
    return (l.x == r.x) && (l.y == r.y);
}

bool operator<(const Point& l, const Point& r) {
    return (l.x < r.x) || (l.y < r.y);
}

unsigned int hexDistance(Point p1, Point p2) {
    unsigned int penalty = ((p1.y % 2 == 0) && (p2.y % 2 == 1) && (p1.x < p2.x)) ||
                           ((p2.y % 2 == 0) && (p1.y % 2 == 1) && (p2.x < p1.x));
    unsigned int dx = std::abs(p2.x - p1.x), dy = std::abs(p2.y - p1.x);
    return std::max(dy, dx + (dx - (dx & 1)) + penalty);
}