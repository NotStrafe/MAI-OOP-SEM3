#include "solution.hpp"
#include <cmath>

void Square::calculateFigureCenter() const {
    _centerX = (__x1 + __x2 + __x3 + __x4) / 4.0;
    _centerY = (__y1 + __y2 + __y3 + __y4) / 4.0;
    _centerCalculated = true;
}

Square::operator double() const {
    double side = std::sqrt(std::pow(__x2 - __x1, 2) + std::pow(__y2 - __y1, 2));
    return side * side;
}


std::ostream& operator<<(std::ostream& os, const Square& square) {
    os << "Square: ((" << square.__x1 << ", " << square.__y1 << "), ("
       << square.__x2 << ", " << square.__y2 << "), ("
       << square.__x3 << ", " << square.__y3 << "), ("
       << square.__x4 << ", " << square.__y4 << "))";
    return os;
}

std::istream& operator>>(std::istream& is, Square& square) {
    is >> square.__x1 >> square.__y1
       >> square.__x2 >> square.__y2
       >> square.__x3 >> square.__y3
       >> square.__x4 >> square.__y4;
    return is;
}