#include "solution.hpp"

int main() {
    Array array(10);

    Square* square = new Square();
    Rectangle* rectangle = new Rectangle();
    Trapezoid* trapezoid = new Trapezoid();

    std::cout << "Введите координаты для квадрата (x1 y1 x2 y2): ";
    std::cin >> *square;

    std::cout << "Введите координаты для прямоугольника (x1 y1 x2 y2): ";
    std::cin >> *rectangle;

    std::cout << "Введите координаты для трапеции (x1 y1 x2 y2 x3 y3 x4 y4): ";
    std::cin >> *trapezoid;

    array.addFigure(square);
    array.addFigure(rectangle);
    array.addFigure(trapezoid);

    array.printFigures();
    std::cout << "Общая площадь фигур в массиве: " << array.totalArea() << std::endl;

    return 0;
}