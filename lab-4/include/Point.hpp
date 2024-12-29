#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Scalar.hpp"

template <Scalar T>
class Point {
public:
    T x, y;

    Point();

    Point(T x, T y);

    Point(const Point &other);

    Point(Point &&other) noexcept;

    Point &operator=(const Point &other);

    Point &operator=(Point &&other) noexcept;

    bool operator==(const Point &other) const;

    bool operator!=(const Point &other) const;

    double distance(const Point &other) const;

    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Point<U> &point);
};

#include "Point.cpp"

#endif // POINT_HPP
