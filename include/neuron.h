#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Neuron
{
public:
    Neuron();

    void setValue(double val);

private:
    Neuron* _connections;

    double _value;
    double* _weights;
};

#endif // NEURON_H
