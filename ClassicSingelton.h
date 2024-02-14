#pragma once

class Data
{
    Data(){}
public:
    static Data* get()
    {
        static Data d;
        return &d;
    }
    Data(Data const&) = delete;
    Data(Data&&) = delete;

    int data;
};

//int Data::data = 0;
