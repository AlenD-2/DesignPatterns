#pragma once

#include <string>
#include <vector>
#include <iostream>


class Book
{
public:

    friend std::ostream& operator <<(std::ostream &os, Book obj)
    {
        os << obj._title << ":\n";
        for(const auto &i : obj._children)
        {
            os << "  " << i._title << ":\n";
            for(const auto &j : i._text)
            {
                os << "    " << j << '\n';
            }
        }
        return os;
    }

protected:
    Book(const std::string &title, const std::vector<Book> &child): _title{title}, _children(child)
    {}
    Book(const std::string &title, const std::vector<std::string> &text): _title{title}, _text{text}
    {}


private:
    std::string _title;
    std::vector<std::string> _text;
    std::vector<Book> _children;
};


class A : public Book
{
public:
    A(const std::initializer_list<Book> &list): Book{"Chapter", list}
    {}
};


class C : public Book
{
public:
    C(std::vector<std::string> text): Book{"Lesson", text}
    {}
};
