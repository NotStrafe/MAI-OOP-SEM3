#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>

class Figure {
protected:
    mutable double _area;
    mutable bool _areaCalculated;
    mutable double _centerX, _centerY;
    mutable bool _centerCalculated;

public:
    Figure() : _area(0), _areaCalculated(false), _centerX(0), _centerY(0), _centerCalculated(false) {}

    virtual double getArea() const;
    virtual std::pair<double, double> getFigureCenter() const;

    virtual void calculateFigureCenter() const = 0;
    virtual operator double() const = 0;

    virtual ~Figure() {}
};

class Array {
protected:
    Figure** _elements;
    size_t _capacity;
    size_t _size;

public:
    Array();
    Array(size_t capacity);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    virtual ~Array() noexcept;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    size_t size() const;

    void addFigure(Figure* figure);
    void removeFigure(size_t index);
    void printFigures() const;
    double totalArea() const;
};

// Класс Trapezoid (трапеция)
class Trapezoid : public Figure {
private:
    double __x1, __y1, __x2, __y2, __x3, __y3, __x4, __y4;

public:
    Trapezoid() : __x1(0), __y1(0), __x2(0), __y2(0), __x3(0), __y3(0), __x4(0), __y4(0) {}

    void calculateFigureCenter() const override;
    operator double() const override;

    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    bool operator==(const Trapezoid& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid);
    friend std::istream& operator>>(std::istream& is, Trapezoid& trapezoid);
};

// Класс Square (квадрат)
class Square : public Figure {
private:
    double __x1, __y1, __x2, __y2, __x3, __y3, __x4, __y4;

public:
    Square() : __x1(0), __y1(0), __x2(0), __y2(0), __x3(0), __y3(0), __x4(0), __y4(0) {}

    void calculateFigureCenter() const override;
    operator double() const override;

    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    bool operator==(const Square& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Square& square);
    friend std::istream& operator>>(std::istream& is, Square& square);
};

// Класс Rectangle (прямоугольник)
class Rectangle : public Figure {
private:
    double __x1, __y1, __x2, __y2, __x3, __y3, __x4, __y4;

public:
    Rectangle() : __x1(0), __y1(0), __x2(0), __y2(0), __x3(0), __y3(0), __x4(0), __y4(0) {}

    void calculateFigureCenter() const override;
    operator double() const override;

    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    bool operator==(const Rectangle& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);
    friend std::istream& operator>>(std::istream& is, Rectangle& rectangle);
};

#endif