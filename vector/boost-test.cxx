#define BOOST_TEST_MODULE mVector tests
#include <boost/test/included/unit_test.hpp>
#include "mVector.h"

#define SUITE_START BOOST_AUTO_TEST_SUITE
#define SUITE_END BOOST_AUTO_TEST_SUITE_END

#define TEST BOOST_AUTO_TEST_CASE

mVector<int> testVec;



// Tests start
SUITE_START(Vector_initilization)
	TEST(Vector_correctly_created)
	{
		testVec = mVector<int>(10,1);
		BOOST_CHECK( testVec.capacity() != 0 );
	}

	TEST(Elements_correctly_initialized)
	{
		for (int i = 0; i < 10; ++i)
		{
			BOOST_CHECK( testVec.at(i) == 1 );			
		}
	}
SUITE_END()

SUITE_START(Vector_operations)
	TEST(Push_an_elem)
	{
		int num = 40;
		testVec = mVector<int>(5,-1);
		testVec.push(num);
		BOOST_CHECK( testVec.at( testVec.size()-1)==num);
	}

	TEST(Resizing_a_vector)
	{
		testVec = mVector<int>(7,1);
		int prevCap = testVec.capacity();
		testVec.push(1);
		testVec.push(2);
		int newCap = testVec.capacity();
		BOOST_CHECK(newCap > prevCap);
		BOOST_CHECK( testVec.at( testVec.size()-1)==2);
		BOOST_CHECK( testVec.at( testVec.size()-2)==1);
		BOOST_CHECK( testVec.at(0)==1);
	}

	TEST(Inserting_an_element)
	{
		int num = 40;
		testVec = mVector<int>(5,-1);
		testVec.insert(0,num);
		BOOST_CHECK( testVec.at(0)==num);

		testVec = mVector<int>(7,-1);
		testVec.insert(2,num);
		BOOST_CHECK( testVec.at(2)==num);
		testVec.insert(3,num+1);
		BOOST_CHECK( testVec.at(3)==num+1);
		BOOST_CHECK( testVec.at(2)==num);
	}

	TEST(Prepending_an_element)
	{
		int num=99;
		testVec = mVector<int>(3,1);
		testVec.prepend(0);
		testVec.prepend(1);
		BOOST_CHECK( testVec.at(0) == 1);
		BOOST_CHECK( testVec.at(1) == 0);
		BOOST_CHECK( testVec.size() == 5);
	}

	TEST(Popping_an_element)
	{
		testVec = mVector<int>(3,1);
		testVec.push(12);
		testVec.push(991);
		int prevSize = testVec.size();
		BOOST_CHECK( testVec.pop() == 991);
		int newSize = testVec.size();
		BOOST_CHECK( prevSize - newSize == 1);
		BOOST_CHECK( testVec.at(newSize-1) == 12);
	}

SUITE_END()




