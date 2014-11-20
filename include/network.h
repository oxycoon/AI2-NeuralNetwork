#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"

#include <vector>



class Network
{
public:
    Network(int in, int hidden, int out);
    ~Network();

    void resetNetwork();



private:
    int _countInput, _countHidden, _countOutput;

    Neuron* _input;
    Neuron* _hidden;
    Neuron* _output;



    double LEARNING_RATE = 0.001;
    double TARGET_ACCURACY = 90.0;
    double MOMENTUM = 0.9;
    int MAX_EPOCHS = 1000;

    void initNeurons(int in, int hidden, int out);
    void initWeights();

};

#endif // NETWORK_H
