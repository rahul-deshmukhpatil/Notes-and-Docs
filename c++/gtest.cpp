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

you can pass different flags to control and run specific tests. 
manually invoking InitGoogleTest() function reads all flags and runs the test
but with lgtest-main you don't need to do this.

# Assertions

ASSERT_TRUE(cond)	Fails if cond is false; aborts test on failure.
EXPECT_FALSE(cond)	Fails if cond is true; continues test on failure.

ASSERT_EQ(val1, val2)	Fails if val1 != val2; aborts test on failure.
EXPECT_NE(val1, val2)	Fails if val1 == val2; continues test on failure.
ASSERT_LT(val1, val2)	Fails if val1 >= val2; aborts test on failure.
ASSERT_GT(val1, val2)	Fails if val1 <= val2; aborts test on failure.

ASSERT_FLOAT_EQ(val1, val2)	Fails if val1 and val2 differ more than float precision.
ASSERT_NEAR(val1, val2, abs_error)	Fails if abs(val1 - val2) > abs_error.

ASSERT_STREQ(str1, str2)	Fails if strcmp(str1, str2) != 0.
ASSERT_STRNE(str1, str2)	Fails if strcmp(str1, str2) == 0.

ASSERT_STRCASEEQ(str1, str2)	Fails if strcasecmp(str1, str2) != 0.
ASSERT_STRCASENE(str1, str2)	Fails if strcasecmp(str1, str2) == 0.

EXPECT_THAT(value1, StartsWith("Hello"));
EXPECT_THAT(value2, MatchesRegex("Line \\d+"));
ASSERT_THAT(value3, AllOf(Gt(5), Lt(10)));


ASSERT_THROW(stmt, ExType)	Fails if stmt does not throw ExType.
ASSERT_NO_THROW(stmt)	Fails if stmt throws any exception.
ASSERT_ANY_THROW(stmt)	Fails if stmt does not throw any exception.

SUCCEED()	Marks success at a point in test; purely documentary.
FAIL()	Unconditionally fails and aborts the current test.


EXPECT_PRED(pred, v1, ..., vn)
ASSERT_PRED(pred, v1, ..., vn)	Passes if pred(v1, ..., vn) returns true; prints argument values on failure. (n = 1..5)

ASSERT_PRED_FORMAT(formatter, v1, ..., vn)
Like EXPECT_PREDn but uses a custom formatter for richer failure messages. (n = 1..5)

auto formatter = [] (const char* m_expr, const char* n_expr, int m, int n) {
	if (MutuallyPrime(m, n)) return testing::AssertionSuccess();

	return testing::AssertionFailure() << m_expr << " and " << n_expr
      << " (" << m << " and " << n << ") are not mutually prime, "
	        << "as they have a common divisor " << SmallestPrimeCommonDivisor(m, n);
} 


Death	

EXPECT_DEATH(stmt, regex)
ASSERT_DEATH(stmt, regex)	Passes if stmt causes the process to die and stderr matches regex.

EXPECT_DEATH_IF_SUPPORTED(stmt, regex)
ASSERT_DEATH_IF_SUPPORTED(stmt, regex)	Same as above, but only runs if death tests are supported on the platform.

EXPECT_EXIT(stmt, predicate, regex)
ASSERT_EXIT(stmt, predicate, regex)	Passes if stmt exits and exit code satisfies predicate; stderr must match regex.

EXPECT_EXIT(NormalExit(), testing::ExitedWithCode(0), "Success");
EXPECT_EXIT(NormalExit(), testing::KilledBySignal(9), "Success");

EXPECT_DEBUG_DEATH(stmt, regex)
ASSERT_DEBUG_DEATH(stmt, regex)	Like EXPECT_DEATH, but only checks in debug builds.

Generalised Matcher	EXPECT_THAT(value, matcher)
ASSERT_THAT(value, matcher)	Passes if value matches the given matcher (from GoogleMock).



