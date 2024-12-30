#include "solution.hpp"
#include <cmath>

void Trapezoid::calculateFigureCenter() const {
    _centerX = (__x1 + __x2 + __x3 + __x4) / 4.0;
    _centerY = (__y1 + __y2 + __y3 + __y4) / 4.0;
    _centerCalculated = true;
}
Trapezoid::operator double() const {
    double area = 0.5 * std::abs(
        __x1 * __y2 + __x2 * __y3 + __x3 * __y4 + __x4 * __y1 - 
        (__y1 * __x2 + __y2 * __x3 + __y3 * __x4 + __y4 * __x1)
    );

    return area;
}





std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid) {
    os << "Trapezoid: ((" << trapezoid.__x1 << ", " << trapezoid.__y1 << "), ("
       << trapezoid.__x2 << ", " << trapezoid.__y2 << "), ("
       << trapezoid.__x3 << ", " << trapezoid.__y3 << "), ("
       << trapezoid.__x4 << ", " << trapezoid.__y4 << "))";
    return os;
}

std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) {
    is >> trapezoid.__x1 >> trapezoid.__y1
       >> trapezoid.__x2 >> trapezoid.__y2
       >> trapezoid.__x3 >> trapezoid.__y3
       >> trapezoid.__x4 >> trapezoid.__y4;
    return is;
}