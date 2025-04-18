#ifndef SHAPES_H
#define SHAPES_H

#include <memory>
#include <cmath>
#include <stdexcept>

// Abstract base class
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

// Circle implementation
class Circle : public Shape {
    double radius;
public:
    explicit Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

// Triangle implementation
class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
};

// Square implementation
class Square : public Shape {
    double side;
public:
    explicit Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

// Factory class
class ShapeFactory {
public:
    enum ShapeType { CIRCLE, TRIANGLE, SQUARE };

    static std::unique_ptr<Shape> createShape(ShapeType type, double a, double b = 0) {
        switch (type) {
            case CIRCLE:
                return std::make_unique<Circle>(a);
            case TRIANGLE:
                return std::make_unique<Triangle>(a, b);
            case SQUARE:
                return std::make_unique<Square>(a);
            default:
                throw std::invalid_argument("Invalid ShapeType");
        }
    }
};

#endif // SHAPES_H
