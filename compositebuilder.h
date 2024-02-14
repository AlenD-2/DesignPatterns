#pragma once

#include <string>
#include <iostream>

namespace CompositeBuilder {


class PersonAddressBuilder;
class PersonJobBuilder;
class PersonBuilder;


class Person
{
    friend PersonAddressBuilder;
    friend PersonJobBuilder;
    friend std::ostream& operator << (std::ostream& os, Person obj)
    {
        os << "city: " << obj.city << "\tCountry: "<<obj.country
           << "\nCompany: " << obj.company << "\tPosition: " << obj.position;
        return os;
    }

public:
//    static PersonBuilder& create();

private:
    std::string city, country;
    std::string company, position;

//    static PersonBuilder p;
};


class PersonBuilderBase
{
protected:
    Person &person;

public:
    PersonBuilderBase(Person &person): person{person}
    {}
    ~PersonBuilderBase();

    PersonAddressBuilder& lives();
    PersonJobBuilder& work();

    operator Person()
    {
        return person;
    }

    PersonAddressBuilder* addressBuilder=nullptr;
    PersonJobBuilder* jobBuilder=nullptr;
};


class PersonBuilder : public PersonBuilderBase
{
    Person _person;
public:
    PersonBuilder(): PersonBuilderBase{_person}
    {}
};


class PersonAddressBuilder : public PersonBuilderBase
{
    typedef PersonAddressBuilder self;

public:
    PersonAddressBuilder(PersonBuilderBase *parent): PersonBuilderBase{*parent}
    {}

    self& at(const std::string &city)
    {
        person.city = city;
        return *this;
    }

    self& in(const std::string& country)
    {
        person.country = country;
        return *this;
    }
};


class PersonJobBuilder : public PersonBuilderBase
{
public:
    PersonJobBuilder(PersonBuilderBase *parent): PersonBuilderBase{*parent}
    {}

    PersonJobBuilder& at(const std::string &company)
    {
        person.company = company;
        return *this;
    }

    PersonJobBuilder& as(const std::string& position)
    {
        person.position = position;
        return *this;
    }
};


}
