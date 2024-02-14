#pragma once

#include <QDebug>
#include <QString>

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
        qDebug() << "Circle shape, radius is: " << _radius;
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
    ColoredShape(Shape& shape, const QString& color): _shape(shape), _color(color)
    {}
    void print()const override
    {
        _shape.print();
        qDebug() << "color is: " << _color;
    }

private:
    Shape& _shape;
    QString _color;
};


class TransparentShape : public Shape
{
public:
    TransparentShape(Shape& shape, int transparency): _shape(shape), _transparency(transparency)
    {}
    void print()const override
    {
        _shape.print();
        qDebug() << "transparency is: " << _transparency;
    }

private:
    Shape& _shape;
    int _transparency;
};
