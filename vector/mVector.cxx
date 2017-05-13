#include "mVector.h"

int nextPow2(int k) 
{
    int x = 1;
    while( x < k ) x*=2;
    return x;
}

template<class T >
mVector::mVector(int size, T init)
{
    capacity = nextPow2(size);
    start = (T*) malloc( sizeof(T) * capacity );

    T *p = start;
    for( int i=0; i<size; i++)
    {
        *p = init;
        p++;
    }
}

