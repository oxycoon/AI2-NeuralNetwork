#ifndef DATAENTRY_H
#define DATAENTRY_H

class DataEntry
{
public:
    DataEntry(double* p, double* t);
    ~DataEntry();

    double* _pattern;
    double* _target;
};

#endif // DATAENTRY_H
