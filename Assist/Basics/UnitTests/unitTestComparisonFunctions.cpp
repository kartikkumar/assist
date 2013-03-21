/*    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *
 *    Redistribution and use in source and binary forms, with or without modification, are
 *    permitted provided that the following conditions are met:
 *      - Redistributions of source code must retain the above copyright notice, this list of
 *        conditions and the following disclaimer.
 *      - Redistributions in binary form must reproduce the above copyright notice, this list of
 *        conditions and the following disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *      - Neither the name of the Delft University of Technology nor the names of its contributors
 *        may be used to endorse or promote products derived from this software without specific
 *        prior written permission.
 *
 *    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
 *    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *    COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 *    OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      130314    K. Kumar          File created.
 *
 *    References
 *
 *    Notes
 *
 */

#define BOOST_TEST_MAIN

#include <stdexcept>
#include <string>

#include <boost/test/unit_test.hpp>

#include "Assist/Basics/comparisonFunctions.h"

namespace assist
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_comparison_functions )

//! Test implementation of function to check if integer is within specified range.
BOOST_AUTO_TEST_CASE( testCheckInRangeFunctionForIntegers )
{
    // Set integer to check and range upper and lower bounds.
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
    // Set integer to check and range upper and lower bounds.
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

BOOST_AUTO_TEST_CASE( testCheckInRangeFunctionForDoubles )
{
    // Set double to check and range upper and lower bounds.
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
    // Set double to check and range upper and lower bounds.
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
    // Set string to check and range upper and lower bounds.
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
    // Set string to check and range upper and lower bounds.
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

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace assist
