#ifndef TRAPEZE_HPP
#define TRAPEZE_HPP

#include "Figure.hpp"
#include "Point.hpp"
#include "Array.hpp"
#include "Exceptions.hpp"

#include <initializer_list>
#include <iostream>
#include <cmath>

template <Scalar T>
class Trapeze : public Figure<T> {
public:
    using Figure<T>::Figure;

    Trapeze(std::initializer_list<Point<T>> t);

    template <Scalar U>
    friend std::istream &operator>>(std::istream &in, Trapeze<U> &trapeze);
};

#include "Trapezoid.cpp"

#endif // TRAPEZE_HPP
