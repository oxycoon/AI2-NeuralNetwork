#include "dataentry.h"

DataEntry::DataEntry(std::vector<double> p, std::vector<double> t): _pattern(p), _target(t)
{

}

DataEntry::~DataEntry()
{
    _pattern.clear();
    _target.clear();
}
