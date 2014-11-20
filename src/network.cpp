#include "network.h"

Network::Network(int in, int hidden, int out): _countInput(in), _countHidden(hidden), _countOutput(out)
{
    initNeurons(in, hidden, out);

}

Network::~Network()
{
    delete[] _hidden;
    delete[] _output;
    delete[] _input;
}

void Network::resetNetwork()
{

}

void Network::initNeurons(int in, int hidden, int out)
{
    _input = new Neuron[in+1];
    for(int i = 0; i < in; i++)
        _input[i].setValue(0.0);

    _input[in].setValue(-1.0);

    _hidden = new Neuron[hidden+1];
    for(int i = 0; i < hidden; i++)
        _hidden[i].setValue(0.0);

    _hidden[hidden].setValue(-1.0);

    _output = new Neuron[out+1];
    for(int i = 0; i < out; i++)
        _output[i].setValue(0.0);
}
