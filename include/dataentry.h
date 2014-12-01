#ifndef DATAENTRY_H
#define DATAENTRY_H

#include <vector>

class DataEntry
{
public:
    DataEntry(std::vector<double> p, std::vector<double> t);
    ~DataEntry();

    std::vector<double> _pattern;
    std::vector<double> _target;
};

#endif // DATAENTRY_H
