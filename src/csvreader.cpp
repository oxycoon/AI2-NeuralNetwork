#include "csvreader.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>



//================================================
//                      DataSet
//================================================

DataSet::DataSet()
{

}

DataSet::~DataSet()
{
    _trainingSet.clear();;
    _testingSet.clear();
    _validationSet.clear();
}

void DataSet::clear()
{
    _trainingSet.clear();;
    _testingSet.clear();
    _validationSet.clear();
}

//================================================
//                      CSVReader
//================================================

CSVReader::CSVReader()
{
}

CSVReader::~CSVReader()
{

}

int CSVReader::getNumberDataSet() const
{
    return _numberDataSet;
}

DataSet *CSVReader::getDataSet()
{
    return &_dataSet;
}

/**
 * @brief CSVReader::readCSVFile
 * @param path
 * @param numberInput
 * @param numberOutput
 * @return
 *
 *  Reads a .csv file with {numberInput} input variables and {numberOutput} output variables.
 */
bool CSVReader::readCSVFile(const char *path, int numberInput, int numberOutput, char* separator)
{
    clearData();

    _numberInput = numberInput;
    _numberOutput = numberOutput;
    _separator = separator;

    std::fstream file;
    file.open(path, std::ios::in);

    if(file.is_open())
    {
        std::string line = "";

        while(!file.eof())
        {
            std::getline(file, line);

            if(line.length() > 2)
                readLine(line);
        }

        return true;
    }
    else
        return false;
}

/**
 * @brief CSVReader::clearData
 *
 *  Clears any existing data.
 */
void CSVReader::clearData()
{
    for(int i = 0; i < (int)_data.size(); i++)
    {
        delete _data[i];
    }
    _data.clear();
    _dataSet.clear();
}

/**
 * @brief CSVReader::readLine
 * @param line
 *
 *  Reads the line and pushes the resulting data entry into the
 *  data set.
 */
void CSVReader::readLine(const std::string &line)
{
    double* pattern = new double[_numberInput];
    double* target = new double[_numberOutput];

    char* cstr = new char[line.size() + 1];
    char* token;

    std::strcpy(cstr, line.c_str());

    int i = 0;
    token = std::strtok(cstr, _separator);

    while(token != NULL && i < (_numberInput + _numberOutput))
    {
        if(i < _numberInput)
            pattern[i] = std::atof(token);
        else
            target[i - _numberInput] = std::atof(token);

        //Move forward
        token = std::strtok(NULL, _separator);
        i++;
    }

    //PRINT FOR DEBUGGING
    std::cout << "pattern: ";
    for (int i=0; i < _numberInput; i++)
    {
        std::cout << pattern[i] << ",";
    }

    std::cout << " target: ";
    for (int i=0; i < _numberOutput; i++)
    {
        std::cout << target[i] << " ";
    }
    std::cout << std::endl;


    _data.push_back(new DataEntry(pattern, target));
}




