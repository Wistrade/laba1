#ifndef ARRAY_H
#define ARRAY_H
#include "number.h"
#include <iostream>
using namespace std;

class Array
{
    unsigned int n;
    number* A;
public:
    friend ostream& operator<< (ostream&, Array&);
    void set(unsigned int i, number val);
    number middle() const;
    number sko() const;
    number sortIncreas() const;
    number sortDecreas() const;
    number changeSize(unsigned int newN);
    number changeElement(unsigned int i, number x);
};

#endif // ARRAY_H
