#include "network.h"

#include <cmath>
#include <iostream>

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

void Network::runTraining(std::vector<DataEntry *> trainingSet, std::vector<DataEntry *> generalizedSet, std::vector<DataEntry *> validationSet)
{
    std::cout << " Neural network training starting " << std::endl
              << "======================================================================" << std::endl
              << "Learning rate: " << _learningRate << ", Momentum: " << _momentum << ", Max epochs: " << _maxEpochs << std::endl
              << "Input: " << _countInput << ", Hidden: " << _countHidden << ", Output" << _countOutput << std::endl
              << "======================================================================" << std::endl;

    _epoch = 0;

    //Runs training using training set for training and generalized set for testing
    while((_trainingSetAccuracy < _targetAccuracy || _generalizationSetAccuracy < _targetAccuracy) && _epoch < _maxEpochs)
    {
        double oldTA = _trainingSetAccuracy;
        double oldGA = _generalizationSetAccuracy;

        runTrainingEpoch(trainingSet);

    }
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

void Network::initWeights()
{

}

void Network::runTrainingEpoch(std::vector<DataEntry *> set)
{
    double incorrectPatterns = 0;
    double meanSquaredError = 0;

    for(int i = 0; i < (int)set.size(); i++)
    {
        feedForward(set[i]->_pattern);
        feedBackward(set[i]->_target);
    }
}

void Network::feedForward(double* input)
{
    //Sets input neurons to input values
    for(int i = 0; i < _countInput; i++)
    {
        _input[i].setValue(input[i]);
    }

    //Calculates the hidden layer
    for(int i = 0; i < _countHidden; i++)
    {
        //Resets value
        _hidden[i].setValue(0.0);

        for(int j = 0; j <= _countInput; j++)
        {
            _hidden[i].addToValue(_input[i].getValue() * _input[j].getWeight(i));
        }
        _hidden[i].setValue(activationFunction(_hidden[i].getValue() ) );
    }

    //Calculates the output layer
    for(int i = 0; i <= _countOutput; i++)
    {
        //Resets value
        _output[i].setValue(0.0);

        for(int j = 0; j < _countHidden; j++)
        {
            _output[i].addToValue(_hidden[i].getValue() * _hidden[j].getWeight(i));
        }
        _output[i].setValue(activationFunction(_output[i].getValue() ) );
    }

}

void Network::feedBackward(double* targets)
{
    //Modify deltas between hidden and output
    for(int i = 0; i < _countOutput; i++)
    {
        _outputErrorGradient[i] = calculateOutputErrorGradient(targets[i], _output[i].getValue());

        for(int j = 0; j <= _countHidden; j++)
        {
            if(!_useBatch)
            {
                _hidden[j].setDelta(i, _learningRate * _hidden[i].getValue() * _outputErrorGradient[i] + _momentum * _hidden[i].getDelta(i));
            }
            else
            {
                _hidden[j].addToDelta(i, _learningRate * _hidden[j].getValue() * _outputErrorGradient[i]);
            }
        }
    }
    //Modify deltas between input and hidden
    for(int i = 0; i < _countHidden; i++)
    {

    }
}

double Network::activationFunction(double x)
{
    //Sigmoid function
    return 1 / (1 + std::exp(-x));
}

/**
 * @brief Network::calculateOutputErrorGradient
 * @param target Target value
 * @param actual Actual value
 * @return Error between the target and actual
 *
 *  Calculates the error gradient between the target and actual value.
 */
double Network::calculateOutputErrorGradient(double target, double actual)
{
    return actual * (1 - actual) * (target - actual);
}

/**
 * @brief Network::calculateHiddenErrorGradient
 * @param index
 * @return
 *
 *  Calculates the error gradient at the hidden node at index between the hidden layer
 *  and input layer.
 */
double Network::calculateHiddenErrorGradient(int index)
{
    double weightSum = 0;

    for(int i = 0; i < _countOutput; i++)
    {
        weightSum += _hidden[index].getWeight(i) * _outputErrorGradient[i];
    }

    return _hidden[index].getValue() * (1 - _hidden[index].getValue()) * weightSum;
}
