#pragma once

#include <vector>

class Neuron
{
public:
    Neuron()
    {
        static int id{1};
        this->id = id++;
    }
    std::vector<Neuron*> in, out;
    int id;
    void connect_to(Neuron& neuron)
    {
        this->out.push_back(&neuron);
        neuron.in.push_back(this);
    }
};


