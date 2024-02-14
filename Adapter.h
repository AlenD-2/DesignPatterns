#pragma once

#include <vector>


namespace Adapter {

class Point
{
public:
    Point(int x, int y): x(x), y(y)
    {}
    int x{}, y{};
};


class Line
{
public:
    Line(const Point& start, const Point& end): start(start), end(end)
    {}
    Point start, end;
};


class LineToPointAdapter
{
public:
    LineToPointAdapter(const Line& line)
    {
        points.clear();
        // if vertical line
        if(line.start.y == line.end.y)
        {
            for(int i=line.start.x ; i<=line.end.x ; i++)
            {
                points.push_back(Point(i,line.start.y));
            }
        }
        // if horizontal line
        else if(line.start.x == line.end.x)
        {
            for(int i=line.start.y ; i<line.end.y ; i++)
            {
                points.push_back(Point(line.start.x,i));
            }
        }
    }
    std::vector<Point> points;
};

}
