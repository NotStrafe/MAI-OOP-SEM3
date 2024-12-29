#include "solution.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(FigureTest, ArrayTotalArea) {
    Array array(10);  
    
    Trapezoid* trapezoid = new Trapezoid();
    Square* square = new Square();
    Rectangle* rectangle = new Rectangle();

    std::istringstream is1("0 0 4 0 3 2 0 2");
    std::istringstream is2("1 1 3 1 3 3 1 3");
    std::istringstream is3("0 0 4 0 4 3 0 3");

    is1 >> *trapezoid;
    is2 >> *square;
    is3 >> *rectangle;

    array.addFigure(trapezoid);
    array.addFigure(square);
    array.addFigure(rectangle);

    double totalArea = array.totalArea();

    ASSERT_NEAR(totalArea, 7 + 4 + 12, 0.5);
}

TEST(FigureTest, ArrayTotalAreaWithDeleteElement) {
    Array array(10);  
    
    Trapezoid* trapezoid = new Trapezoid();
    Square* square = new Square();
    Rectangle* rectangle = new Rectangle();

    std::istringstream is1("0 0 4 0 3 2 0 2");
    std::istringstream is2("1 1 3 1 3 3 1 3");
    std::istringstream is3("0 0 4 0 4 3 0 3");

    is1 >> *trapezoid;
    is2 >> *square;
    is3 >> *rectangle;

    array.addFigure(trapezoid);
    array.addFigure(square);
    array.addFigure(rectangle);

    array.removeFigure(1);

    double totalArea = array.totalArea();

    ASSERT_NEAR(totalArea, 7 + 12, 0.5);
}

TEST(FigureTest, TrapezoidOutputStream) {
    Trapezoid* trapezoid = new Trapezoid();
    
    std::istringstream is("0 0 4 0 3 2 0 2");
    is >> *trapezoid;
    
    std::ostringstream os;
    os << *trapezoid;
    
    std::string expectedOutput = "Trapezoid: ((0, 0), (4, 0), (3, 2), (0, 2))";
    ASSERT_EQ(os.str(), expectedOutput);
}

TEST(FigureTest, SquareInputStream) {
    Square* square = new Square();
    
    std::istringstream is("1 1 3 1 3 3 1 3");
    is >> *square;
    
    double area = square->getArea();
    
    ASSERT_NEAR(area, 4, 0.5);
}

TEST(FigureTest, SquareOperatorDouble) {
    Square* square = new Square();
    
    std::istringstream is("1 1 3 1 3 3 1 3");
    is >> *square;
    
    double area = static_cast<double>(*square);
    
    ASSERT_NEAR(area, 4, 0.5);
}

TEST(FigureTest, SquareCenter) {
    Square* square = new Square();
    
    std::istringstream is("1 1 3 1 3 3 1 3");
    is >> *square;
    
    square->calculateFigureCenter();
    auto center = square->getFigureCenter();
    
    ASSERT_NEAR(center.first, 2, 0.5);
    ASSERT_NEAR(center.second, 2, 0.5);
}

TEST(FigureTest, TrapezoidCenterAndArea) {
    Trapezoid* trapezoid = new Trapezoid();
    
    std::istringstream is("0 0 4 0 3 2 0 2");
    is >> *trapezoid;
    
    trapezoid->calculateFigureCenter();
    auto center = trapezoid->getFigureCenter();
    
    double area = trapezoid->getArea();
    
    ASSERT_NEAR(area, 7, 0.5);
    ASSERT_NEAR(center.first, 2, 0.5);
    ASSERT_NEAR(center.second, 1, 0.5);
}