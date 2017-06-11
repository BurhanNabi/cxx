#define BOOST_TEST_MODULE MergeSort tests
#include <vector>
#include <boost/test/included/unit_test.hpp>
#include "mStack.h"

#define SUITE_START BOOST_AUTO_TEST_SUITE
#define SUITE_END BOOST_AUTO_TEST_SUITE_END

#define TEST BOOST_AUTO_TEST_CASE


SUITE_START(Test_stack)
	TEST(push)
	{
		mStack<int> stack;
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(4);
		BOOST_CHECK(stack.top() == 4);
	}

	TEST(pop)
	{
		mStack<int> stack;
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(4);
		BOOST_CHECK(stack.top() == 4);

		BOOST_CHECK(stack.size()==4);
		BOOST_CHECK(stack.pop() == 4);
		BOOST_CHECK(stack.pop() == 3);
		BOOST_CHECK(stack.pop() == 2);
		BOOST_CHECK(stack.pop() == 1);
		BOOST_CHECK(stack.size() == 0);
	}

SUITE_END()
