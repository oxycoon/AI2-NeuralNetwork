#ifndef DATASET_H
#define DATASET_H

#include "dataentry.h"
#include "neuron.h"

#include <vector>

namespace DataSet {
    std::vector<DataEntry*> trainingSet;
    std::vector<DataEntry*> testingSet;
    std::vector<DataEntry*> validationSet;
}


#endif // DATASET_H
