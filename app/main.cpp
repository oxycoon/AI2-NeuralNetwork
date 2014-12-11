#include <iostream>

#include "network.h"
#include "csvreader.h"
//#include ""

using namespace std;

int main()
{
    std::cout << std::endl;
    std::cout << "NEURAL NETWORK" << std::endl;

    CSVReader reader;
    reader.readCSVFile("../res/trainingset.csv", 7, 5, ",");

    Network nn(7, 21, 5);
    nn.setLearningParameters(0.01, 0.8);
    nn.setTargetAccuracy(95.0);
    nn.setMaxEpochs(100);

    DataSet* set;

    for(int i = 0; i < reader.getNumberDataSet(); i++)
    {
        set = reader.getDataSet();
        nn.runTraining(set->_trainingSet, set->_testingSet, set->_validationSet);
    }

    std::cout << " -- END OF NETWORK -- " << std::endl;

    //char c; std::cin >> c;

    return 0;
}

