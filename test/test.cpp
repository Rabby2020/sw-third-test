#include "../src/shape.cpp"
#include <gtest/gtest.h>

TEST(ShapeFactoryTest, CircleArea) {
    auto circle = ShapeFactory::createShape(ShapeFactory::CIRCLE, 2.0);
    EXPECT_NEAR(circle->area(), M_PI * 4.0, 1e-5);
}

TEST(ShapeFactoryTest, TriangleArea) {
    auto triangle = ShapeFactory::createShape(ShapeFactory::TRIANGLE, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(triangle->area(), 6.0);
}

TEST(ShapeFactoryTest, SquareArea) {
    auto square = ShapeFactory::createShape(ShapeFactory::SQUARE, 5.0);
    EXPECT_DOUBLE_EQ(square->area(), 25.0);
}

TEST(ShapeFactoryTest, InvalidShapeTypeThrows) {
    EXPECT_THROW(ShapeFactory::createShape(static_cast<ShapeFactory::ShapeType>(-1), 1.0), std::invalid_argument);
}
