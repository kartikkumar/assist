/*    
 *    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *    See COPYING for license details.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      130923    K. Kumar          File created.
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

#include <TudatCore/Astrodynamics/BasicAstrodynamics/physicalConstants.h> 
#include <TudatCore/Mathematics/BasicMathematics/mathematicalConstants.h> 

#include "Assist/Astrodynamics/astrodynamicsBasics.h"

namespace assist
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_astrodynamics_basics )

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
    const double computedMassOfSphere = astrodynamics::computeMassOfSphere(
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
            = astrodynamics::computeGravitationalParameter( massOfBody );

    // Check that computed gravitational parameter of body matches expected value.
    BOOST_CHECK_CLOSE_FRACTION( computedGravitationalParameter, expectedGravitationalParameter,
                                std::numeric_limits< double >::epsilon( ) );
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace assist