#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Figure.hpp"
#include "Point.hpp"
#include "Array.hpp"
#include "Exceptions.hpp"

#include <initializer_list>
#include <iostream>

template <Scalar T>
class Square : public Figure<T> {
public:
    using Figure<T>::Figure;

    Square(std::initializer_list<Point<T>> t);

    template <Scalar U>
    friend std::istream &operator>>(std::istream &in, Square<U> &square);
};

#include "Square.cpp"

#endif // SQUARE_HPP
