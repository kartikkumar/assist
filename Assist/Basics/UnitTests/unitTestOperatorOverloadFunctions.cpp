/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    All rights reserved.
 *    See http://bit.ly/1jern3m for license details.
 */

#include <iostream>

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

#include "Assist/Basics/operatorOverloadFunctions.h"

namespace assist
{
namespace unit_tests
{

using namespace basics::operator_overload_functions;

//! Define test data struct.
struct TestData
{
public:

    TestData( const double aValue )
        : value( aValue )
    { }

    const double value;

protected:
private:
};

//! Overload == operator for TestData struct.
inline bool operator==( const TestData& testData1, const TestData& testData2 )
{
    return testData1.value == testData2.value;
}

//! Overload < operator for TestData struct.
inline bool operator<( const TestData& testData1, const TestData& testData2 )
{
    return testData1.value < testData2.value;
}

BOOST_AUTO_TEST_SUITE( test_operator_overload_functions )

//! Test implementation of == operator overload function (const).
BOOST_AUTO_TEST_CASE( testConstEqualOperatorOverloadFunction )
{
    // Declare structs with values.
    const TestData test( 1.2 );
    const TestData test2( 1.2 );

    // Check that calling operator on the TestData structs yields expected result.
    BOOST_CHECK( test == test2 );
}

//! Test implementation of == operator overload function (non-const).
BOOST_AUTO_TEST_CASE( testNonConstEqualOperatorOverloadFunction )
{
    // Declare structs with values.
    TestData test( 1.2 );
    TestData test2( 1.2 );

    // Check that calling operator on the TestData structs yields expected result.
    BOOST_CHECK( test == test2 );
}

//! Test implementation of != operator overload function (const).
BOOST_AUTO_TEST_CASE( testConstNotEqualOperatorOverloadFunction )
{
    // Declare structs with values.
    const TestData test( 1.2 );
    const TestData test2( 2.3 );

    // Check that calling operator on the TestData structs yields expected result.
    BOOST_CHECK( test != test2 );
}

//! Test implementation of != operator overload function (non-const).
BOOST_AUTO_TEST_CASE( testNonConstNotEqualOperatorOverloadFunction )
{
    // Declare data structs with values.
    TestData test( 1.2 );
    TestData test2( 2.3 );

    // Check that calling operator on the TestData structs yields expected result.
    BOOST_CHECK( test != test2 );
}

//! Test implementation of < operator overload function (const).
BOOST_AUTO_TEST_CASE( testConstLessThanOperatorOverloadFunction )
{
    // Declare structs with values.
    const TestData test( 1.2 );
    const TestData test2( 2.3 );

    // Check that calling operator on the TestData structs yields expected result.
    BOOST_CHECK( test < test2 );
}

//! Test implementation of < operator overload function (non-const).
BOOST_AUTO_TEST_CASE( testNonConstLessThanOperatorOverloadFunction )
{
    // Declare structs with values.
    TestData test( 1.2 );
    TestData test2( 2.3 );

    // Check that calling operator on the TestData structs yields expected result.
    BOOST_CHECK( test < test2 );
}

//! Test implementation of > operator overload function (const).
BOOST_AUTO_TEST_CASE( testConstGreaterThanOperatorOverloadFunction )
{
    // Declare structs with values.
    const TestData test( 2.3 );
    const TestData test2( 1.2 );

    // Check that calling operator on the TestData structs yields expected result.
    BOOST_CHECK( test > test2 );
}

//! Test implementation of > operator overload function (non-const).
BOOST_AUTO_TEST_CASE( testNonConstGreaterThanOperatorOverloadFunction )
{
    // Declare structs with values.
    TestData test( 2.3 );
    TestData test2( 1.2 );

    // Check that calling operator on the TestData structs yields expected result.
    BOOST_CHECK( test > test2 );
}

//! Test implementation of <= operator overload function (const).
BOOST_AUTO_TEST_CASE( testConstLessThanOrEqualOperatorOverloadFunction )
{
    // Test less than case.
    {
        // Declare structs with values.
        const TestData test( 1.2 );
        const TestData test2( 2.3 );

        // Check that calling operator on the TestData structs yields expected result.
        BOOST_CHECK( test <= test2 );
    }

    // Test equal to case.
    {
        // Declare structs with values.
        const TestData test( 1.2 );
        const TestData test2( 1.2 );

        // Check that calling operator on the TestData structs yields expected result.
        BOOST_CHECK( test <= test2 );
    }
}

//! Test implementation of >= operator overload function (const).
BOOST_AUTO_TEST_CASE( testConstGreaterThanOrEqualOperatorOverloadFunction )
{
    // Test greater than case.
    {
        // Declare structs with values.
        const TestData test( 2.3 );
        const TestData test2( 1.2 );

        // Check that calling operator on the TestData structs yields expected result.
        BOOST_CHECK( test >= test2 );
    }

    // Test equal to case.
    {
        // Declare structs with values.
        const TestData test( 2.3 );
        const TestData test2( 2.3 );

        // Check that calling operator on the TestData structs yields expected result.
        BOOST_CHECK( test >= test2 );
    }
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace assist
