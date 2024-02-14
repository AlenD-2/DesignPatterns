#pragma once

#include <QDebug>
#include <math.h>

namespace Factory {


class Point
{
    friend class PointFactory;

public:
    void print()const
    {
        qDebug() << "(" << _a << "," << _b << ")";
    }
private:
    Point(float a, float b): _a{a}, _b{b}
    {}

    float _a, _b;
};



class PointFactory
{
public:
    static Point newCartesian(float x, float y)
    {
        return Point{x,y};
    }
    static Point newPolar(float r, float theta)
    {
        return Point{r*std::cos(theta), r*std::sin(theta)};
    }
};


}
