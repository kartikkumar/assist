/*    
 *    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *    See COPYING for license details.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      130328    K. Kumar          File created; migrated code from basics.h. 
 *      130329    K. Kumar          Added unit tests for Julian days <-> seconds.
 *
 *    References
 *
 *    Notes
 *
 */

#define BOOST_TEST_MAIN

#include <limits>

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

//! Test implementation of function to convert Julian days to seconds.
BOOST_AUTO_TEST_CASE( testConvertJulianDaysToSecondsFunction )
{
    // Set expected number of seconds in 1 Julian days.
    const double expectedOneJulianDayInSeconds = 24.0 * 3600.0;

    // Convert 1 Julian day to seconds.
    const double computedOneJulianDayInSeconds 
            = astrodynamics::convertJulianDaysToSeconds( 1.0 );

    // Check that the computed number of seconds matches the expected value.
    BOOST_CHECK_CLOSE_FRACTION( computedOneJulianDayInSeconds,
                                expectedOneJulianDayInSeconds,
                                std::numeric_limits< double >::epsilon( ) );
}

//! Test implementation of function to convert seconds to Julian days.
BOOST_AUTO_TEST_CASE( testConvertSecondsToJulianDaysFunction )
{
    // Set expected number of Julian days.
    const double expectedJulianDays= 1.0;

    // Convert seconds.
    const double computedJulianDays
            = astrodynamics::convertSecondsToJulianDays( 86400.0 );

    // Check that the computed number of Julian days matches the expected value.
    BOOST_CHECK_CLOSE_FRACTION( computedJulianDays,
                                expectedJulianDays,
                                std::numeric_limits< double >::epsilon( ) );
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace assist