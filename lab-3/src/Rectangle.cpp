#include "solution.hpp"
#include <cmath>

void Rectangle::calculateFigureCenter() const {
    _centerX = (__x1 + __x2 + __x3 + __x4) / 4.0;
    _centerY = (__y1 + __y2 + __y3 + __y4) / 4.0;
    _centerCalculated = true;
}

Rectangle::operator double() const {
    double width = std::sqrt(std::pow(__x2 - __x1, 2) + std::pow(__y2 - __y1, 2));
    double height = std::sqrt(std::pow(__x3 - __x2, 2) + std::pow(__y3 - __y2, 2));
    return width * height;
}


std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle) {
    os << "Rectangle: ((" << rectangle.__x1 << ", " << rectangle.__y1 << "), ("
       << rectangle.__x2 << ", " << rectangle.__y2 << "), ("
       << rectangle.__x3 << ", " << rectangle.__y3 << "), ("
       << rectangle.__x4 << ", " << rectangle.__y4 << "))";
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
    is >> rectangle.__x1 >> rectangle.__y1
       >> rectangle.__x2 >> rectangle.__y2
       >> rectangle.__x3 >> rectangle.__y3
       >> rectangle.__x4 >> rectangle.__y4;
    return is;
}
