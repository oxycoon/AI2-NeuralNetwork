#include <iostream>

#include "network.h"
#include "csvreader.h"

using namespace std;

int main()
{
    std::cout << std::endl;
    std::cout << "NEURAL NETWORK" << std::endl;



    CSVReader reader;
    reader.readCSVFile("../res/set1.csv", 8, 1, ";");

    Network myNetwork(6, 12, 1);



    return 0;
}

