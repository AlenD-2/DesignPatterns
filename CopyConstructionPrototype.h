#pragma once

#include <string>

class Address
{
public:
    Address(const std::string& city, const std::string& country): city(city), country(country)
    {}

    std::string city;
    std::string country;
};


class Contact
{
public:
    Contact(const std::string& name, const Address& address): name(name), address(new Address(address))
    {}
    Contact(const Contact &contact): name(contact.name), address(new Address(*contact.address))
    {}
    ~Contact()
    {
        if(address)
            delete address;
    }

    std::string name;
    Address* address = nullptr;
};
