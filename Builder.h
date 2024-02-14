#pragma once

#include <vector>
#include <memory>
#include <string>

namespace Builder
{

class stringBuilder;

class stringElement
{
public:
    std::string text;
    stringElement(const std::string &str)
    {
        text = str;
    }

    static std::unique_ptr<stringBuilder> build()
    {
        return std::make_unique<stringBuilder>();
    }
};

class stringBuilder
{
public:
    std::vector<stringElement> stringList;
    stringBuilder* add(const std::string &str)
    {
        stringList.push_back(stringElement(str));
        return this;
    }
    operator stringElement ()const
    {
        return stringList.at(0);
    }
};

}
