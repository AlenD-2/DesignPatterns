#pragma once

#include <string>
#include <iostream>


namespace DynamicDecorator {

class Shape
{
public:
    virtual void print()const=0;
};

class Circle : public Shape
{
public:
    Circle(const float radius): _radius(radius)
    {}
    void print()const override
    {
        std::cout << "Circle shape, radius is: " << _radius << '\n';
    }
    void resize(float newRadius)
    {
        _radius = newRadius;
    }

private:
    float _radius{};
};

class ColoredShape : public Shape
{
public:
    ColoredShape(Shape& shape, const std::string& color): _shape(shape), _color(color)
    {}
    void print()const override
    {
        _shape.print();
        std::cout << "color is: " << _color << '\n';
    }

private:
    Shape& _shape;
    std::string _color;
};


class TransparentShape : public Shape
{
public:
    TransparentShape(Shape& shape, int transparency): _shape(shape), _transparency(transparency)
    {}
    void print()const override
    {
        _shape.print();
        std::cout << "transparency is: " << _transparency << '\n';
    }

private:
    Shape& _shape;
    int _transparency;
};

}
