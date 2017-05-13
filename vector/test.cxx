#include <iostream>
#include "mVector.h"

using namespace std;

mVector<int> testVec;

void testInit();


int main(int argc, char const *argv[])
{
	cout << "Vector class test" << endl;

	cout << "Test initilization" << endl;
	testInit();



	return 0;
}

void testInit()
{
	testVec = mVector<int>(10,1);
	
	assert( testVec.capacity() != 0)
	{
		cout << "\tVector created successfully" << endl;
	}
	else
	{
		cout << "\tVector creation failed" << endl;
		exit(0);
	}
}
