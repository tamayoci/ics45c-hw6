#include "circle.hpp"
#include <iostream>
#include <numbers>

Circle::Circle(Point center, std::string name, int radius)
    : Shape(center, name), radius{radius}
{
}

