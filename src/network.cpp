#include "network.h"

Network::Network(int in, int hidden, int out): _countInput(in), _countHidden(hidden), _countOutput(out)
{
    setupNeurons();
    setupWeights();
    setupDeltas();
    setupErrorGradients();
}

Network::~Network()
{
    /*delete[] _hidden;
    delete[] _output;
    delete[] _input;

    delete[] _hiddenErrorGradient;
    delete[] _outputErrorGradient;*/
}

void Network::setLearningParameters(double learningRate, double momentum)
{
    _learningRate = learningRate;
    _momentum = momentum;
}

void Network::setMaxEpochs(unsigned int max)
{
    _maxEpochs = max;
}

void Network::setTargetAccuracy(double target)
{
    _targetAccuracy = target;
}

void Network::useBatchLearning()
{
    _useBatch = true;
}

void Network::useStochasticLearning()
{
    _useBatch = false;
}

void Network::resetNetwork()
{

}

void Network::setupNeurons()
{
    _input = new Neuron[_countInput+1];
    for(int i = 0; i < _countInput; i++)
        _input[i].setValue(0.0);

    _input[_countInput].setValue(-1.0);

    _hidden = new Neuron[_countHidden+1];
    for(int i = 0; i < _countHidden; i++)
        _hidden[i].setValue(0.0);

    _hidden[_countHidden].setValue(-1.0);

    _output = new Neuron[_countOutput+1];
    for(int i = 0; i < _countOutput; i++)
        _output[i].setValue(0.0);
}

void Network::setupWeights()
{
    for(int i = 0; i < _countHidden; i++)
    {
        _input[i].initializeWeights(_countHidden);
    }
    for(int i = 0; i < _countOutput; i++)
    {
        _hidden[i].initializeWeights(_countOutput);
    }
}

void Network::setupDeltas()
{
    for(int i = 0; i < _countHidden; i++)
    {
        _input[i].initializeDeltas(_countHidden + 1);
    }
    for(int i = 0; i < _countOutput; i++)
    {
        _hidden[i].initializeDeltas(_countOutput + 1);
    }
}

void Network::setupErrorGradients()
{
    _hiddenErrorGradient = new (double[_countHidden + 1]);
    for(int i = 0; i <= _countHidden; i++)
    {
        _hiddenErrorGradient[i] = 0;
    }
    _outputErrorGradient = new (double[_countOutput + 1]);
    for(int i = 0; i <= _countOutput; i++)
    {
        _outputErrorGradient[i] = 0;
    }
}
