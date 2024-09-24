#ifndef VECTOR_2_HPP
#define VECTOR_2_HPP

struct Vector2
{
private:
    float _x;
    float _y;

public:
    Vector2();
    Vector2(float x, float y);

    bool operator==(const Vector2 &rhs) const;

    float getX() const;
    float getY() const;

    void setX(float x);
    void setY(float y);
    void set(float x, float y);
};

#endif