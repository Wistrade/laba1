#include "array.h"
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

void Array::set(unsigned int i, number val)
{
    if (n > 0 && i < n)
    {
        A[i] = val;
    }
}

number Array::middle() const
{
    number d = 0;
    for (unsigned int i = 0; i < n; i++)
        d += A[i];
    d = d / n;
    return d;
}

number Array::sko() const
{
    number d = 0;
    for (unsigned int i = 0; i < n; i++)
        d += A[i];
    d = d / n;
    number res = 0;
    for (unsigned int i = 0; i < n; ++i) {
        res += pow(A[i] - d, 2);
    }
    res /= n;
    number skoRes = sqrt(res);
    return skoRes;
}

number Array::sortIncreas() const
{
    sort(A, A + n);
}

number Array::sortDecreas() const
{
    sort(A, A + n, greater<number>());
}

number Array::changeSize(unsigned int newN)
{
    number* newA = new number[newN];
    for (int i = 0; i < min(n, newN); ++i) {
        newA[i] = A[i];
    }

    if (newN > n) {
        for (int i = n; i < newN; ++i) {
            newA[i] = 0.0;
        }
    }
    delete[] A;
    A = newA;
    n = newN;
}

number Array::changeElement(unsigned int i, number x)
{
    A[i] = x;
}

ostream& operator<< (ostream& os, Array& A)
{
    for (unsigned int i = 0; i < n; i++)
    {
        os << A[i] << " ";
        os << endl;
    }
    return os;
}