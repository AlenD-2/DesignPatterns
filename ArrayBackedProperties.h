#pragma once

#include <algorithm>
#include <array>
#include <numeric>


namespace ArrayBacked {

class Score
{
public:
    enum Property
    {
        lesson1,
        lesson2,
        lesson3,
        count
    };
    Score& setProperty(int value, int property)
    {
        properties.at(property) = value;
        return *this;
    }
    int sum()
    {
        return std::accumulate(properties.begin(), properties.end(), 0);
    }
    int max()
    {
        return *std::max_element(properties.begin(), properties.end());
    }
    double avverage()
    {
        return sum()/static_cast<double>(count);
    }

private:
    std::array<int,count> properties;
};

}
