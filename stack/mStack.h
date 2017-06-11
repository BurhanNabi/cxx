#include <iostream>
#include <vector>
#include <limits.h>

#define DEBUG 0
#define DEBUG_ONLY if(DEBUG)


template<class T>
class mStack
{
	std::vector<T> elements;
public:
	mStack();
	~mStack();


	void push(T elem);
	T pop();
	int size();
	T top();

};

template<class T>
mStack<T>::mStack()
{
	elements = std::vector<T>();
}

template<class T>
mStack<T>::~mStack(){}


template<class T>
void mStack<T>::push(T elem)
{
	this->elements.push_back(elem);
	DEBUG_ONLY{ std::cout << "Added " << elem << std::endl;}
}

template<class T>
T mStack<T>::top()
{
	int size = this->elements.size();
	if( size > 0)
	{
		return this->elements[size-1];
	}
	else
	{
		std::string s = "No elements in the stack";
		throw s;
	}
}

template<class T>
int mStack<T>::size()
{
	return this->elements.size();
}


template<class T>
T mStack<T>::pop()
{
	int s = this->elements.size();
	if(s > 0)
	{
		T elem = this->elements[s-1];
		this->elements.pop_back();
		DEBUG_ONLY{ std::cout << "Element removed\n";}
		return elem;
	}
	else
	{
		std::string s = "No elements in the stack";
		throw s;
	}
}