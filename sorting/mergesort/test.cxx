#define BOOST_TEST_MODULE MergeSort tests
#include <vector>
#include <boost/test/included/unit_test.hpp>
#include "mergesort.h"
#include <stdlib.h>
#include <algorithm>

#define SUITE_START BOOST_AUTO_TEST_SUITE
#define SUITE_END BOOST_AUTO_TEST_SUITE_END

#define TEST BOOST_AUTO_TEST_CASE

using std::vector;

// Tests start

SUITE_START(Test_merging)
	TEST(Merge_function_size_2)
	{
		vector<int> orig, ans;
		orig={1,0};
		ans={0,1};
		MergeSort::merge(orig,0,1,2);
		BOOST_CHECK(orig == ans);
	}
	TEST(Merge_function_size_3)
	{
		vector<int> orig, ans;
		orig={2,0,1};
		ans={0,1,2};
		MergeSort::merge(orig,0,1,3);
		BOOST_CHECK(orig == ans);
	}
	TEST(Merge_function_size_5)
	{
		vector<int> orig, ans;
		orig={1,5,0,2,4};
		ans={0,1,2,4,5};
		MergeSort::merge(orig,0,2,5);
		BOOST_CHECK(orig == ans);
	}
	TEST(Merge_function_size_6)
	{
		vector<int> orig, ans;
		orig={1,5,7,0,2,4};
		ans={0,1,2,4,5,7};
		MergeSort::merge(orig,0,3,6);
		BOOST_CHECK(orig == ans);
	}
	TEST(Merge_function_size_7)
	{
		vector<int> orig, ans;
		orig={1,5,7,0,2,4,100};
		ans={0,1,2,4,5,7,100};
		MergeSort::merge(orig,0,3,7);
		BOOST_CHECK(orig == ans);
	}
	TEST(Merge_in_middle_of_array)
	{
		vector<int> orig, ans;
		orig={-10,-9,-8,1,5,7,0,2,4,100};
		ans={-10,-9,-8,0,1,2,4,5,7,100};
		MergeSort::merge(orig,3,6,9);
		BOOST_CHECK(orig == ans);
	}
SUITE_END()
	
SUITE_START(Test_mergesort)
	TEST(MergeSort_size_2)
	{
		vector<int> orig, ans;
		orig={1,0};
		ans={0,1};
		MergeSort::mergeSort(orig,0,2);
		BOOST_CHECK(orig == ans);
	}
	TEST(MergeSort_size_3)
	{
		vector<int> orig, ans;
		orig={2,0,1};
		ans={0,1,2};
		MergeSort::mergeSort(orig,0,3);
		BOOST_CHECK(orig == ans);
	}
	TEST(MergeSort_size_5)
	{
		vector<int> orig, ans;
		orig={1,5,0,2,4};
		ans={0,1,2,4,5};
		MergeSort::mergeSort(orig,0,5);
		BOOST_CHECK(orig == ans);
	}
	TEST(MergeSort_size_6)
	{
		vector<int> orig, ans;
		orig={1,5,7,0,2,4};
		ans={0,1,2,4,5,7};
		MergeSort::mergeSort(orig,0,6);
		BOOST_CHECK(orig == ans);
	}
	TEST(MergeSort_size_7)
	{
		vector<int> orig, ans;
		orig={1,5,7,0,2,4,100};
		ans={0,1,2,4,5,7,100};
		MergeSort::mergeSort(orig,0,7);
		BOOST_CHECK(orig == ans);
	}
	TEST(MergeSort_large_size)
	{
		vector<int> orig, ans;
		srand(time(NULL));
		int size = rand()%1000000;

		// Fill up with random numbers
		for (int i = 0; i < size; ++i)
			orig.push_back(rand());

		// Get correctly sorted array
		ans = orig;
		std::sort( ans.begin(), ans.end() );

		// Check merge sorted array is same as that sorted by inbuilt sort
		MergeSort::mergeSort( orig,0,orig.size() );
		BOOST_CHECK(orig == ans );
	}
SUITE_END()
