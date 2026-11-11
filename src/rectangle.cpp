#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(Point center, std::string name, int width, int height)
    : Shape(center, name), width(width), height(height) {
}

double Rectangle::area() const {
    return height * width;
}