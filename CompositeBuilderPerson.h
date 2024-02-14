#pragma once

#include "compositebuilder.h"

class Person
{
//    friend PersonAddressBuilder;
//    friend PersonJobBuilder;
    friend std::ostream& operator << (std::ostream& os, Person obj)
    {
        os << "city: " << obj.city << "\tCountry: "<<obj.country
           << "\nCompany: " << obj.company << "\tPosition: " << obj.position;
        return os;
    }

public:
    static PersonBuilder& create()
    {
        return p;
    }

//private:
    std::string city, country;
    std::string company, position;

    static PersonBuilder p;
};
