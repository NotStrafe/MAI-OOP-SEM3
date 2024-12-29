#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Figure.hpp"
#include "Point.hpp"
#include "Array.hpp"
#include "Exceptions.hpp"

#include <initializer_list>
#include <iostream>

template <Scalar T>
class Rectangle : public Figure<T> {
public:
    using Figure<T>::Figure;

    Rectangle(std::initializer_list<Point<T>> t);

    template <Scalar U>
    friend std::istream &operator>>(std::istream &in, Rectangle<U> &rectangle);
};

#include "Rectangle.cpp"

#endif // RECTANGLE_HPP
