#include "neuron.h"

Neuron::Neuron()
{
}

Neuron::~Neuron()
{
    /*delete[] _weights;
    delete[] _deltas;*/
}

void Neuron::setValue(double val)
{
    _value = val;
}

void Neuron::setWeight(int index, double weight)
{
    _weights[index] = weight;
}

void Neuron::setDelta(int index, double delta)
{
    _deltas[index] = delta;
}

double *Neuron::getWeights() const
{
    return _weights;
}

double Neuron::getWeight(int index) const
{
    return _weights[index];
}

double *Neuron::getDeltas() const
{
    return _deltas;
}

double Neuron::getDelta(int index) const
{
    return _deltas[index];
}

double Neuron::getValue() const
{
    return _value;
}

int Neuron::getWeightCount() const
{
    return _weightCount;
}

int Neuron::getDeltaCount() const
{
    return _deltaCount;
}

void Neuron::addToValue(double val)
{
    _value += val;
}

void Neuron::addToDelta(int index, double val)
{
    _deltas[index] += val;
}

void Neuron::initializeWeights(int weights)
{
    _weightCount = weights;
    _weights = new (double[_weightCount]);

    for(int i = 0; i < weights; i++)
    {
        _weights[i] = 0;
    }
}

void Neuron::initializeDeltas(int deltas)
{
    _deltaCount = deltas;
    _deltas = new (double[_deltaCount]);
    for(int i = 0; i < _deltaCount; i++)
    {
        _deltas[i] = 0;
    }
}
