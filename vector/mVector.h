#include <iostream>

using namespace std;

int nextPow2(int k);

template <class T>
class mVector
{
    int numElems, totalCapacity;
    T *start;

public:
    mVector(){};
    mVector(int size, T init);
    T at(int index);
    int inline size() {return numElems;}
    int inline capacity() {return totalCapacity;}
    bool inline isEmpty() {return (numElems == 0);}
    void push(T elem);
    void resize(int);
    void insert(int,T);
    void prepend(T elem);
    T pop();
};


int nextPow2(int k) 
{
    int x = 1;
    while( x < k ) x*=2;
    return x;
}

template<class T>
mVector<T>::mVector(int size, T init)
{
    this->totalCapacity = nextPow2(size);
    this->numElems = size;

    start = NULL;

    try
    {
        start =  new T[totalCapacity];
    }
    catch (exception& e)
    {
        this->totalCapacity = 0;
        cout << "Insufficient Memory: " << e.what() << endl;
        exit(1);
    }

    T *p = start;
    for( int i=0; i<size; i++)
    {
        *p = init;
        p++;
    }
}

template<class T>
T mVector<T>::at(int i)
{
    if( i < numElems) return *(start + i);
    else 
    {
        cout << "Index(" << i <<") out of bounds" << endl;
        exit(1);
    }
}

template <class T>
void mVector<T>::push(T elem)
{
    if(totalCapacity == numElems)
    {
        resize(2*numElems);
    }
    *(start+numElems) = elem;
    numElems++;
}

template <class T>
void mVector<T>::resize(int newCap)
{
    int *nVec;
    try
    {
        nVec = new T[newCap];
    }catch( exception &e)
    {
        cout << "Insufficient memory" << e.what() << endl;
        exit(1);
    }

    // Copy previous vector
    for (int i = 0; i < numElems; ++i)
        *(nVec+i) = *(start+i);

    totalCapacity = newCap;

    delete start;
    start = nVec;
}

template <class T>
void mVector<T>::insert(int index, T elem)
{

    if(totalCapacity == numElems)
    {
        resize(2*numElems);
    }
    
    // Shift elements
    for(int i=numElems; i>index; i--)
        *(start+i) = *(start+i-1);
    
    *(start+index) = elem;
    numElems++;
}

template <class T>
void mVector<T>::prepend(T elem)
{
    insert(0,elem);
}

template <class T>
T mVector<T>::pop()
{
    numElems--;
    return *(start+numElems);
}

