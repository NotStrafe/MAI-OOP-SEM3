#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <memory>
#include <string>
#include <initializer_list>
#include <iostream>
#include "Point.hpp"
#include "Array.hpp"
#include "Exceptions.hpp"

template <Scalar T>
class Figure {
protected:
    std::shared_ptr<Array<Point<T>>> _crds;
    std::string _name;

public:
    Figure();

    Figure(std::initializer_list<Point<T>> t);

    Figure(const Figure &other);

    Figure(Figure &&other) noexcept;

    virtual ~Figure() = default;

    Figure &operator=(const Figure &other);

    Figure &operator=(Figure &&other) noexcept;

    bool operator==(const Figure &other) const;

    bool operator!=(const Figure &other) const;

    template <Scalar U>
    friend std::ostream &operator<<(std::ostream &os, const Figure<U> &figure);

    std::shared_ptr<Array<Point<T>>> get_crds_array() const;

    std::string get_name();

    std::shared_ptr<Point<T>> get_center() const;

    explicit operator double() const;

    template <Scalar U>
    friend std::istream &operator>>(std::istream &in, Figure<U> &figure);
};

#include "Figure.cpp"

#endif // FIGURE_HPP
