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
    Contact(const std::string& name, const Address& address): name(name), address(new Address(address))
    {}
    Contact(const Contact &contact): name(contact.name), address(new Address(*contact.address))
    {}

public:
    ~Contact()
    {
        if(address)
            delete address;
    }

    class ContactFactory
    {
        static Contact tehran;
    public:
        static Contact newTehranContact(const std::string& name)
        {
            tehran.name = name;
            return Contact{tehran};
        }
    };

    std::string name;
    Address* address = nullptr;
};

Contact Contact::ContactFactory::tehran = Contact{"",Address{"tehran", "iran"}};
