#include "dataentry.h"

DataEntry::DataEntry(double *p, double *t): _pattern(p), _target(t)
{

}

DataEntry::~DataEntry()
{
    delete[] pattern;
    delete[] target;
}
