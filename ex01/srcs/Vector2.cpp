#include "Vector2.hpp"

Vector2::Vector2() : _x(0), _y(0)
{
}

Vector2::Vector2(float x, float y) : _x(x), _y(y)
{
}

bool Vector2::operator==(const Vector2 &rhs) const
{
    return _x == rhs._x && _y == rhs._y;
}

float Vector2::getX() const
{
    return _x;
}

float Vector2::getY() const
{
    return _y;
}

void Vector2::setX(float x)
{
    _x = x;
}

void Vector2::setY(float y)
{
    _y = y;
}

void Vector2::set(float x, float y)
{
    this->setX(x);
    this->setY(y);
}