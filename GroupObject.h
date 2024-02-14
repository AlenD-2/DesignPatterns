#pragma once

#include <string>
#include <iostream>
#include <vector>

class IName
{
public:
    virtual void print()=0;
};

class Name : public IName
{
    std::string name;
public:
    Name(std::string name): name(name)
    {}
    void print() override
    {
        std::cout << name << '\n';
    }
};

class NameGroup : public IName
{
public:
    void print() override
    {
        for(auto name : group)
            name->print();
    }
    NameGroup& add(IName* name)
    {
        group.push_back(name);
        return *this;
    }

private:
    std::vector<IName*> group;
};
