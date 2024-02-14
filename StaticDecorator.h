#pragma once

#include <iostream>
#include <string>


namespace StaticDecorator {

class Shape
{
public:
    virtual void print()const=0;
};

class Circle : public Shape
{
public:
    Circle()
    {}
    Circle(const float radius): radius(radius)
    {}
    void print()const override
    {
        std::cout << "Circle shape, radius is: " << radius << '\n';
    }
    void resize(float newRadius)
    {
        radius = newRadius;
    }

    float radius{};
};

template<typename T>
class ColoredShape : public T
{
    static_assert(std::is_base_of<Shape,T>::value, "Template argument must be a Shape");
public:
    ColoredShape()
    {}
    template<typename...Args>
    ColoredShape(const std::string& color, Args ...arg): T(std::forward<Args>(arg)...), color(color)
    {}
    void print()const override
    {
        T::print();
        std::cout << "color is: " << color << '\n';
    }

    std::string color;
};

template<typename T>
class TransparentShape : public T
{
    static_assert(std::is_base_of<Shape,T>::value, "Template argument must be a Shape");
public:
    TransparentShape()
    {}
    template<typename ...Args>
    TransparentShape(int transparency, Args ...arg): T(std::forward<Args>(arg)...), transparency(transparency)
    {}
    void print()const override
    {
        T::print();
        std::cout << "transparency is: " << transparency << '\n';
    }

    int transparency;
};

}
