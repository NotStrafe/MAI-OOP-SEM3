#include "Point.hpp"

template <Scalar T> class Point {
    public:
        T x, y;

    public:
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
        friend std::ostream& operator<<(std::ostream &os, const Point<U> &point);
}

Point<T>::Point() : x(static_cast<T>(0)), y(static_cast<T>(0)) {}

Point<T>::Point(const T x, const T y) : x(x), y(y) {}

bool Point<T>::operator==(const Point &other) const {
    return x == other.x && y == other.y;
}

bool Point<T>::operator!=(const Point &other) const {
    return x != other.x || y != other.y;
}

double Point<T>::distance(const Point &other) const {
    return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

std::ostream& operator<<(std::ostream &os, const Point<T> &point) {
    os << '(' << point.x << ", " << point.y << ')';
    return os;
}