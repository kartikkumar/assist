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
 *      130328    K. Kumar          File created; migrated code from basics.h
 *
 *    References
 *
 *    Notes
 *
 */

#define BOOST_TEST_MAIN

#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

#include <Assist/Astrodynamics/unitConversions.h>

namespace assist
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_basics )


//! Test implementation of function to convert Julian years to seconds.
BOOST_AUTO_TEST_CASE( testConvertJulianYearsToSecondsFunction )
{
    // Set expected number of seconds in 1 Julian year.
    const double expectedOneJulianYearInSeconds = 365.25 * 24.0 * 3600.0;

    // Convert 1 Julian year to seconds.
    const double computedOneJulianYearInSeconds 
    		= astrodynamics::convertJulianYearsToSeconds( 1.0 );

    // Check that the computed number of seconds matches the expected value.
    BOOST_CHECK_CLOSE_FRACTION( computedOneJulianYearInSeconds,
                                expectedOneJulianYearInSeconds,
                                std::numeric_limits< double >::epsilon( ) );
}

//! Test implementation of function to convert seconds to Julian years.
BOOST_AUTO_TEST_CASE( testConvertSecondsToJulianYearsFunction )
{
    // Set expected number of Julian years.
    const double expectedJulianYears = 1.0;

    // Convert seconds.
    const double computedJulianYears 
    		= astrodynamics::convertSecondsToJulianYears( 365.25 * 86400.0 );

    // Check that the computed number of Julian years matches the expected value.
    BOOST_CHECK_CLOSE_FRACTION( computedJulianYears,
                                expectedJulianYears,
                                std::numeric_limits< double >::epsilon( ) );
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace assist