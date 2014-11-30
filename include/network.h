#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"
#include "dataentry.h"

#include <vector>

#define LEARNING_RATE 0.001
#define MOMENTUM 0.9
#define MAX_EPOCHS 1500
#define TARGET_ACCURACY 90


//Inspired by https://takinginitiative.wordpress.com/2008/04/23/basic-neural-network-tutorial-c-implementation-and-source-code/

class Network
{
public:
    Network(int in, int hidden, int out);
    ~Network();

    void setLearningParameters(double learningRate, double momentum);
    void setMaxEpochs(unsigned int max);
    void setTargetAccuracy(double target);

    void useBatchLearning();
    void useStochasticLearning();

    void resetNetwork();

    void runTraining(std::vector<DataEntry*> trainingSet, std::vector<DataEntry*> generalizedSet, std::vector<DataEntry*> validationSet);



private:
    int _countInput, _countHidden, _countOutput;

    Neuron* _input;
    Neuron* _hidden;
    Neuron* _output;

    double *_hiddenErrorGradient;
    double *_outputErrorGradient;

    unsigned int _epoch;
    unsigned int _maxEpochs;

    double _targetAccuracy;
    double _learningRate;
    double _momentum;

    double _trainingSetAccuracy;
    double _validationSetAccuracy;
    double _generalizationSetAccuracy;
    double _trainingSetError;
    double _validationSetError;
    double _generalizationSetError;

    bool _useBatch;

    void setupNeurons();
    void setupWeights();
    void setupDeltas();
    void setupErrorGradients();

    void initWeights();

    void runTrainingEpoch(std::vector<DataEntry*> set);
    void feedForward(double* inputs);
    void feedBackward(double* targets);
    void updateWeights();

    double activationFunction(double x);
    double calculateOutputErrorGradient(double target, double actual);
    double calculateHiddenErrorGradient(int index);

    int roundOutput(double output);
};

#endif // NETWORK_H
