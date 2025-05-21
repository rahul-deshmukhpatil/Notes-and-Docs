declar test class with

#include <gtest/gtest.h>

// SampleTest a fixture class
// its object is created per test
struct SampleTest : testing::test
{
	protected:
		SetUp() override; // called after constr, before test execution
		TearDown() override; // called after test is run
		~SampleTest() override; // called after tear down
}

TEST : for  simple functions
TEST_F : for testing the fixter class functions

EXPECT_* if fails to check statement still proceeds to next statement in the test 
ASSERT_* stops the execution of test if test throws

if you link againt lgtest_main it has definition for main function which runs
the RUN_ALL_TESTS functions.
