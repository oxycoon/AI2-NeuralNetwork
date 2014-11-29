#ifndef NEURON_H
#define NEURON_H

//#include <vector>

class Neuron
{
public:
    Neuron();
    ~Neuron();

    void setValue(double val);
    void setWeight(int index, double weight);
    void setDelta(int index, double delta);

    double* getWeights() const;
    double getWeight(int index) const;
    double* getDeltas() const;
    double getDelta(int index) const;
    double getValue() const;

    int getWeightCount() const;
    int getDeltaCount() const;

    void initializeWeights(int weights);
    void initializeDeltas(int deltas);

private:
    double _value;
    double* _weights;
    double* _deltas;

    int _weightCount;
    int _deltaCount;
};

#endif // NEURON_H
