#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Neuron
{
public:
    Neuron();

private:
    std::vector<Neuron*> _connections;
};

#endif // NEURON_H
