/*    
 *    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *    See COPYING for license details.
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

#include "Assist/Basics/basics.h"

namespace assist
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_basics )

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
} // namespace assist
