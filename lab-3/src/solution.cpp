#include "solution.hpp"
#include <cmath>

double Figure::getArea() const {
    if (!_areaCalculated) {
        _area = static_cast<double>(*this); 
        _areaCalculated = true;
    }
    return _area;
}

std::pair<double, double> Figure::getFigureCenter() const {
    if (!_centerCalculated) {
        calculateFigureCenter();
        _centerCalculated = true;
    }
    return {_centerX, _centerY};
}

Array::Array() : _capacity(10), _size(0) {
    _elements = new Figure*[_capacity];
}

Array::Array(size_t capacity) : _capacity(capacity), _size(0) {
    _elements = new Figure*[_capacity];
}

Array::~Array() noexcept {
    for (size_t i = 0; i < _size; ++i) {
        delete _elements[i];
    }
    delete[] _elements;
}

void Array::addFigure(Figure* figure) {
    if (_size >= _capacity) {
        _capacity *= 2;
        Figure** newElements = new Figure*[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            newElements[i] = _elements[i];
        }
        delete[] _elements;
        _elements = newElements;
    }
    _elements[_size++] = figure;
}

void Array::removeFigure(size_t index) {
    if (index < _size) {
        delete _elements[index];
        for (size_t i = index; i < _size - 1; ++i) {
            _elements[i] = _elements[i + 1];
        }
        --_size;
    }
}

void Array::printFigures() const {
    for (size_t i = 0; i < _size; ++i) {
        std::cout << *_elements[i] << std::endl;
    }
}

double Array::totalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < _size; ++i) {
        total += _elements[i]->getArea();
    }
    return total;
}


