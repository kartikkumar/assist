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
 *      130323    K. Kumar          File created.
 *      130328    K. Kumar          Completed unit tests for boiler plate functions.
 *
 *    References
 *
 *    Notes
 *
 */

#define BOOST_TEST_MAIN

#include <iostream>

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/test/unit_test.hpp>

#include "Assist/Basics/operatorOverloadFunctions.h"

namespace assist
{
namespace unit_tests
{

using namespace basics;

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

//! Define typedef for shared-pointer to TestData.
typedef boost::shared_ptr< TestData > TestDataPointer;

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
