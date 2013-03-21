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
 *      130211    K. Kumar          File created.
 *      130308    K. Kumar          Added unit test for various free functions.
 *
 *    References
 *
 *    Notes
 *
 */

#define BOOST_TEST_MAIN

#include <map>
#include <typeinfo>

#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

#include "GeneralCPlusPlusTools/Basics/basics.h"
#include "GeneralCPlusPlusTools/Basics/commonTypedefs.h"

namespace general_c_plus_plus_tools
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_basics )

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

//! Test implementation of function to convert Julian years to seconds.
BOOST_AUTO_TEST_CASE( testConvertJulianYearsToSecondsFunction )
{
    // Set expected number of seconds in 1 Julian year.
    const double expectedOneJulianYearInSeconds = 365.25 * 24.0 * 3600.0;

    // Convert 1 Julian year to seconds.
    const double computedOneJulianYearInSeconds = basics::convertJulianYearsToSeconds( 1.0 );

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
    const double computedJulianYears = basics::convertSecondsToJulianYears( 365.25 * 86400.0 );

    // Check that the computed number of Julian years matches the expected value.
    BOOST_CHECK_CLOSE_FRACTION( computedJulianYears,
                                expectedJulianYears,
                                std::numeric_limits< double >::epsilon( ) );
}

//! Test implementation of function to convert of Full-Width Half-Maximum to standard deviation.
BOOST_AUTO_TEST_CASE( testConvertFullWidthHalfMaximumToStandardDeviationFunction )
{
    // Set FWHM.
    const double fullWidthHalfMaximum = 10.0;

    // Set expected standard deviation for specified FWHM.
    const double expectedStandardDeviation
            = fullWidthHalfMaximum / ( 2.0 * std::sqrt( 2.0 * std::log( 2.0 ) ) );

    // Compute standard deviation from FWHM.
    const double computedStandardDeviation
            = basics::convertFullWidthHalfMaximumToStandardDeviation( fullWidthHalfMaximum );

    // Check that the computed standard deviation matches the expected value.
    BOOST_CHECK_CLOSE_FRACTION( computedStandardDeviation,
                                expectedStandardDeviation,
                                std::numeric_limits< double >::epsilon( ) );
}

//! Test implementation of function to compute mass of sphere of uniform density.
BOOST_AUTO_TEST_CASE( testComputeMassOfSphereFunction )
{
    // Set radius of sphere [m].
    const double radiusOfSphere = 25.6;

    // Set bulk density of sphere [kg/m^3].
    const double bulkDensityOfSphere = 1234.5;

    // Set expected mass of sphere [kg].
    const double expectedMassOfSphere
            = 4.0 / 3.0 * tudat::basic_mathematics::mathematical_constants::PI
            * radiusOfSphere * radiusOfSphere * radiusOfSphere * bulkDensityOfSphere;

    // Compute mass of sphere [kg].
    const double computedMassOfSphere = basics::computeMassOfSphere(
                radiusOfSphere, bulkDensityOfSphere );

    // Check if computed mass of sphere matches expected value.
    BOOST_CHECK_CLOSE_FRACTION( computedMassOfSphere, expectedMassOfSphere,
                                std::numeric_limits< double >::epsilon( ) );
}

//! Test implementation of function to compute gravitational parameter of body.
BOOST_AUTO_TEST_CASE( testComputeGravitationalParameterFunction )
{
    // Set mass of body [kg].
    const double massOfBody = 123.456;

    // Set expected gravitational parameter of body [m^3/s^2].
    const double expectedGravitationalParameter
            = massOfBody * tudat::physical_constants::GRAVITATIONAL_CONSTANT;

    // Compute gravitational parameter of body [m^3/s^2].
    const double computedGravitationalParameter
            = basics::computeGravitationalParameter( massOfBody );

    // Check that computed gravitational parameter of body matches expected value.
    BOOST_CHECK_CLOSE_FRACTION( computedGravitationalParameter, expectedGravitationalParameter,
                                std::numeric_limits< double >::epsilon( ) );
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace general_c_plus_plus_tools
