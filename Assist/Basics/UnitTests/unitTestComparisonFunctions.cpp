/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    All rights reserved.
 *    See http://bit.ly/1jern3m for license details.
 */

#include <stdexcept>
#include <string>

#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

#include "Assist/Basics/commonTypedefs.h"
#include "Assist/Basics/comparisonFunctions.h"

namespace assist
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_comparison_functions )

//
// Test checkGreaterThan() function.
//

//! Test implementation of function to check if integer is greater than a lower bound.
BOOST_AUTO_TEST_CASE( testCheckGreaterThanFunctionForIntegers )
{
    // Set integer to check against lower bound.
    const int integerToCheck = 10;
    const std::string integerToCheckName = "Test integer";
    const int lowerBound = -5;

    // Check if integer is greater than lower bound. The function should return the integer, to
    // indicate that the check passed successfully.
    const int checkedInteger = basics::checkGreaterThan(
                integerToCheck, integerToCheckName, lowerBound );

    // Check that test passed and integer was returned.
    BOOST_CHECK_EQUAL( checkedInteger, integerToCheck );
}

//! Test run-time error in checkGreaterThan() function for integers.
BOOST_AUTO_TEST_CASE( testCheckGreaterThanFunctionRunTimeErrorForIntegers )
{
    // Set integer to check against lower bound.
    const int integerToCheck = 10;
    const std::string integerToCheckName = "Test integer";
    const int lowerBound = 20;

    // Check if integer is out of range. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkGreaterThan( integerToCheck, integerToCheckName, lowerBound );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//! Test implementation of function to check if double is greater than a lower bound.
BOOST_AUTO_TEST_CASE( testCheckGreaterThanFunctionForDoubles)
{
    // Set double to check against lower bound.
    const double doubleToCheck = 10.6;
    const std::string doubleToCheckName = "Test double";
    const double lowerBound = -5.2;

    // Check if double is greater than lower bound. The function should return the double, to
    // indicate that the check passed successfully.
    const double checkedDouble = basics::checkGreaterThan(
                doubleToCheck, doubleToCheckName, lowerBound );

    // Check that test passed and double was returned.
    BOOST_CHECK_EQUAL( checkedDouble, doubleToCheck );
}

//! Test run-time error in checkGreaterThan() function for doubles.
BOOST_AUTO_TEST_CASE( testCheckGreaterThanFunctionRunTimeErrorForDoubles )
{
    // Set double to check against lower bound.
    const double doubleToCheck = 10.6;
    const std::string doubleToCheckName = "Test double";
    const double lowerBound = 25.2;

    // Check if double is out of range. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkGreaterThan( doubleToCheck, doubleToCheckName, lowerBound );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//! Test implementation of function to check if string is greater than a lower bound.
BOOST_AUTO_TEST_CASE( testCheckGreaterThanFunctionForStrings )
{
    // Set string to check against lower bound.
    const std::string stringToCheck = "dog";
    const std::string stringToCheckName = "Test string";
    const std::string lowerBound = "cat";

    // Check if string is greater than lower bound. The function should return the string, to
    // indicate that the check passed successfully.
    const std::string checkedString = basics::checkGreaterThan(
                stringToCheck, stringToCheckName, lowerBound );

    // Check that test passed and string was returned.
    BOOST_CHECK_EQUAL( checkedString, stringToCheck );
}

//! Test run-time error in checkGreaterThan() function for strings.
BOOST_AUTO_TEST_CASE( testCheckGreaterThanFunctionRunTimeErrorForStrings )
{
    // Set string to check against lower bound.
    const std::string stringToCheck = "dog";
    const std::string stringToCheckName = "Test string";
    const std::string lowerBound = "mouse";

    // Check if string is out of range. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkGreaterThan( stringToCheck, stringToCheckName, lowerBound );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//
// Test checkLessThan() function.
//

//! Test implementation of function to check if integer is less than an upper bound.
BOOST_AUTO_TEST_CASE( testCheckLessThanFunctionForIntegers )
{
    // Set integer to check against upper bound.
    const int integerToCheck = -5;
    const std::string integerToCheckName = "Test integer";
    const int upperBound = 10;

    // Check if integer is less than lower bound. The function should return the integer, to
    // indicate that the check passed successfully.
    const int checkedInteger = basics::checkLessThan(
                integerToCheck, integerToCheckName, upperBound );

    // Check that test passed and integer was returned.
    BOOST_CHECK_EQUAL( checkedInteger, integerToCheck );
}

//! Test run-time error in checkLessThan() function for integers.
BOOST_AUTO_TEST_CASE( testCheckLessThanFunctionRunTimeErrorForIntegers )
{
    // Set integer to check against upper bound.
    const int integerToCheck = 10;
    const std::string integerToCheckName = "Test integer";
    const int upperBound = -5;

    // Check if integer is out of range. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkLessThan( integerToCheck, integerToCheckName, upperBound );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//! Test implementation of function to check if double is less than a lower bound.
BOOST_AUTO_TEST_CASE( testCheckLessThanFunctionForDoubles )
{
    // Set double to check against upper bound.
    const double doubleToCheck = -10.6;
    const std::string doubleToCheckName = "Test double";
    const double upperBound = 5.2;

    // Check if double is less than upper bound. The function should return the double, to
    // indicate that the check passed successfully.
    const double checkedDouble = basics::checkLessThan(
                doubleToCheck, doubleToCheckName, upperBound );

    // Check that test passed and double was returned.
    BOOST_CHECK_EQUAL( checkedDouble, doubleToCheck );
}

//! Test run-time error in checkLessThan() function for doubles.
BOOST_AUTO_TEST_CASE( testCheckLessThanFunctionRunTimeErrorForDoubles )
{
    // Set double to check against upper bound.
    const double doubleToCheck = 10.6;
    const std::string doubleToCheckName = "Test double";
    const double upperBound = -5.2;

    // Check if double is out of range. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkLessThan( doubleToCheck, doubleToCheckName, upperBound );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//! Test implementation of function to check if string is greater than a lower bound.
BOOST_AUTO_TEST_CASE( testCheckLessThanFunctionForStrings )
{
    // Set string to check against upper bound.
    const std::string stringToCheck = "cat";
    const std::string stringToCheckName = "Test string";
    const std::string upperBound = "dog";

    // Check if string is less than lower bound. The function should return the string, to
    // indicate that the check passed successfully.
    const std::string checkedString = basics::checkLessThan(
                stringToCheck, stringToCheckName, upperBound );

    // Check that test passed and string was returned.
    BOOST_CHECK_EQUAL( checkedString, stringToCheck );
}

//! Test run-time error in checkLessThan() function for strings.
BOOST_AUTO_TEST_CASE( testCheckLessThanFunctionRunTimeErrorForStrings )
{
    // Set string to check against upper bound.
    const std::string stringToCheck = "mouse";
    const std::string stringToCheckName = "Test string";
    const std::string upperBound = "cat";

    // Check if string is out of range. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkLessThan( stringToCheck, stringToCheckName, upperBound );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//
// Test checkInRange() function.
//

//! Test implementation of function to check if integer is within specified range.
BOOST_AUTO_TEST_CASE( testCheckInRangeFunctionForIntegers )
{
    // Set integer to check range upper and lower bounds.
    const int integerToCheck = 10;
    const std::string integerToCheckName = "Test integer";
    const int lowerBound = -5;
    const int upperBound = 25;

    // Check if integer is within specified range. The function should return the integer, to
    // indicate that the range check passed successfully.
    const int checkedInteger = basics::checkInRange(
                integerToCheck, integerToCheckName, lowerBound, upperBound );

    // Check that test passed and integer was returned.
    BOOST_CHECK_EQUAL( checkedInteger, integerToCheck );
}

//! Test implementation of function to check out-of-range integer.
BOOST_AUTO_TEST_CASE( testCheckInRangeFunctionForOutOfRangeInteger )
{
    // Set integer to check range upper and lower bounds.
    const int integerToCheck = 10;
    const std::string integerToCheckName = "Test integer";
    const int lowerBound = 12;
    const int upperBound = 25;

    // Check if integer is out of range. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkInRange( integerToCheck, integerToCheckName, lowerBound, upperBound );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//! Test implementation of function to check if double is within specified range.
BOOST_AUTO_TEST_CASE( testCheckInRangeFunctionForDoubles )
{
    // Set double to check range upper and lower bounds.
    const double doubleToCheck = -12.3;
    const std::string doubleToCheckName = "Test double";
    const double lowerBound = -24.6;
    const double upperBound = 13.4;

    // Check if double is within specified range. The function should return the double, to
    // indicate that the range check passed successfully.
    const double checkedDouble = basics::checkInRange(
                doubleToCheck, doubleToCheckName, lowerBound, upperBound );

    // Check that test passed and double was returned.
    BOOST_CHECK_EQUAL( checkedDouble, doubleToCheck );
}

//! Test implementation of function to check out-of-range double.
BOOST_AUTO_TEST_CASE( testCheckInRangeFunctionForOutOfRangeDouble )
{
    // Set double to check range upper and lower bounds.
    const double doubleToCheck = -12.3;
    const std::string doubleToCheckName = "Test double";
    const double lowerBound = -4.6;
    const double upperBound = 13.4;

    // Check if double is out of range. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkInRange( doubleToCheck, doubleToCheckName, lowerBound, upperBound );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

BOOST_AUTO_TEST_CASE( testCheckInRangeFunctionForStrings )
{
    // Set string to check range upper and lower bounds.
    const std::string stringToCheck = "ball";
    const std::string stringToCheckName = "Test string";
    const std::string lowerBound = "apple";
    const std::string upperBound = "cat";

    // Check if string is within specified range. The function should return the string, to
    // indicate that the range check passed successfully.
    const std::string checkedString = basics::checkInRange(
                stringToCheck, stringToCheckName, lowerBound, upperBound );

    // Check that test passed and string was returned.
    BOOST_CHECK_EQUAL( checkedString, stringToCheck );
}

//! Test implementation of function to check out-of-range string.
BOOST_AUTO_TEST_CASE( testCheckInRangeFunctionForOutOfRangeString )
{
    // Set string to check range upper and lower bounds.
    const std::string stringToCheck = "dog";
    const std::string stringToCheckName = "Test string";
    const std::string lowerBound = "apple";
    const std::string upperBound = "cat";

    // Check if string is out of range. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkInRange( stringToCheck, stringToCheckName, lowerBound, upperBound );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//
// Test checkPositive() function.
//

//! Test implementation of function to check if integer is positive.
BOOST_AUTO_TEST_CASE( testCheckPositiveFunctionForIntegers )
{
    // Set integer to check.
    const int integerToCheck = 10;
    const std::string integerToCheckName = "Test integer";

    // Check if integer is positive. The function should return the integer, to indicate that the
    // sign check passed successfully.
    const int checkedInteger = basics::checkPositive( integerToCheck, integerToCheckName );

    // Check that test passed and integer was returned.
    BOOST_CHECK_EQUAL( checkedInteger, integerToCheck );
}

//! Test implementation of function to check non-positive integer.
BOOST_AUTO_TEST_CASE( testCheckPositiveFunctionForNonPositiveInteger )
{
    // Set integer to check.
    const int integerToCheck = -10;
    const std::string integerToCheckName = "Test integer";

    // Check if integer is positive. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkPositive( integerToCheck, integerToCheckName );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//! Test implementation of function to check if double is positive.
BOOST_AUTO_TEST_CASE( testCheckPositiveFunctionForDoubles )
{
    // Set double to check.
    const double doubleToCheck = 10.33;
    const std::string doubleToCheckName = "Test double";

    // Check if double is positive. The function should return the double, to indicate that the
    // sign check passed successfully.
    const double checkedDouble = basics::checkPositive( doubleToCheck, doubleToCheckName );

    // Check that test passed and double was returned.
    BOOST_CHECK_EQUAL( checkedDouble, doubleToCheck );
}

//! Test implementation of function to check non-positive double.
BOOST_AUTO_TEST_CASE( testCheckPositiveFunctionForNonPositiveDouble )
{
    // Set double to check.
    const double doubleToCheck = -10.33;
    const std::string doubleToCheckName = "Test double";

    // Check if double is positive. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkPositive( doubleToCheck, doubleToCheckName );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//
// Test checkNegative() function.
//

//! Test implementation of function to check if integer is negative.
BOOST_AUTO_TEST_CASE( testCheckNegativeFunctionForIntegers )
{
    // Set integer to check.
    const int integerToCheck = -10;
    const std::string integerToCheckName = "Test integer";

    // Check if integer is negative. The function should return the integer, to indicate that the
    // sign check passed successfully.
    const int checkedInteger = basics::checkNegative( integerToCheck, integerToCheckName );

    // Check that test passed and integer was returned.
    BOOST_CHECK_EQUAL( checkedInteger, integerToCheck );
}

//! Test implementation of function to check non-negative integer.
BOOST_AUTO_TEST_CASE( testCheckNegativeFunctionForNonNegativeInteger )
{
    // Set integer to check.
    const int integerToCheck = 10;
    const std::string integerToCheckName = "Test integer";

    // Check if integer is negative. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkNegative( integerToCheck, integerToCheckName );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//! Test implementation of function to check if double is negative.
BOOST_AUTO_TEST_CASE( testCheckNegativeFunctionForDoubles )
{
    // Set double to check.
    const double doubleToCheck = -10.33;
    const std::string doubleToCheckName = "Test double";

    // Check if double is negative. The function should return the double, to indicate that the
    // sign check passed successfully.
    const double checkedDouble = basics::checkNegative( doubleToCheck, doubleToCheckName );

    // Check that test passed and double was returned.
    BOOST_CHECK_EQUAL( checkedDouble, doubleToCheck );
}

//! Test implementation of function to check non-negative double.
BOOST_AUTO_TEST_CASE( testCheckNegativeFunctionForNonNegativeDouble )
{
    // Set double to check.
    const double doubleToCheck = 10.33;
    const std::string doubleToCheckName = "Test double";

    // Check if double is negative. The function should throw a run-time error, which we will
    // attempt to catch.
    bool isErrorThrown = false;

    try
    {
        basics::checkNegative( doubleToCheck, doubleToCheckName );
    }

    catch ( std::runtime_error& error )
    {
        isErrorThrown = true;
    }

    // Check that test failed and run-time error was thrown.
    BOOST_CHECK( isErrorThrown );
}

//! Test implementation of functor to compare two values in a DoubleKeyDoubleValue map.
BOOST_AUTO_TEST_CASE( testDoubleKeyDoubleValueMapValueComparisonFunctor )
{
    // Set double-key, double-value map.
    basics::DoubleKeyDoubleValueMap testMap;
    testMap[ -2.1 ] = 0.99;
    testMap[ 1.6 ] = -9.44;
    testMap[ 3.2 ] = 12.7;

    // Declare functor object for testing purposes.
    basics::CompareDoubleKeyDoubleValueMapValues comparisonFunctor;

    // Declare map iterators.
    basics::DoubleKeyDoubleValueMap::iterator mapIterator1 = testMap.begin( );
    basics::DoubleKeyDoubleValueMap::iterator mapIterator2 = testMap.begin( );
    mapIterator2++;
    basics::DoubleKeyDoubleValueMap::iterator mapIterator3 = testMap.begin( );
    mapIterator3++;
    mapIterator3++;

    // Run a few checks to ensure that functor is performing as expected.
    BOOST_CHECK( comparisonFunctor( *mapIterator2, *mapIterator1 ) );
    BOOST_CHECK( comparisonFunctor( *mapIterator2, *mapIterator3 ) );
    BOOST_CHECK( !comparisonFunctor( *mapIterator3, *mapIterator1 ) );

    // Check that comparing the same value yields false (strictly "less than" comparison).
    BOOST_CHECK( !comparisonFunctor( *mapIterator1, *mapIterator1 ) );
}

//! Test implementation of functor to compare two values in a DoubleKeyDoubleValue map wrt a
//! reference point.
BOOST_AUTO_TEST_CASE( testDoubleKeyDoubleValueMapValueRelativeDistanceComparisonFunctor )
{
    // Set double-key, double-value map.
    basics::DoubleKeyDoubleValueMap testMap;
    testMap[ -2.1 ] = 0.99;
    testMap[ 1.6 ] = -9.44;
    testMap[ 3.2 ] = 12.7;

    // Declare functor object for testing purposes.
    basics::CompareDoubleKeyDoubleValueMapRelativeDistances comparisonFunctor( 1.2 );

    // Declare map iterators.
    basics::DoubleKeyDoubleValueMap::iterator mapIterator1 = testMap.begin( );
    basics::DoubleKeyDoubleValueMap::iterator mapIterator2 = testMap.begin( );
    mapIterator2++;
    basics::DoubleKeyDoubleValueMap::iterator mapIterator3 = testMap.begin( );
    mapIterator3++;
    mapIterator3++;

    // Run a few checks to ensure that functor is performing as expected.
    BOOST_CHECK( !comparisonFunctor( *mapIterator2, *mapIterator1 ) );
    BOOST_CHECK( comparisonFunctor( *mapIterator2, *mapIterator3 ) );
    BOOST_CHECK( !comparisonFunctor( *mapIterator3, *mapIterator1 ) );

    // Check that comparing the same value yields false (strictly "less than" comparison).
    BOOST_CHECK( !comparisonFunctor( *mapIterator1, *mapIterator1 ) );
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace assist
