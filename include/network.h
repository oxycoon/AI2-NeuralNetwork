#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"

#include <vector>



class Network
{
public:
    Network();

    void resetNetwork();


private:
    std::vector<Neuron*> _input;
    std::vector<Neuron*> _hidden;
    std::vector<Neuron*> _output;

    double LEARNING_RATE = 0.001;
    double TARGET_ACCURACY = 90.0;
    double MOMENTUM = 0.9;
    int MAX_EPOCHS = 1000;

    void initWeights();

};

#endif // NETWORK_H
