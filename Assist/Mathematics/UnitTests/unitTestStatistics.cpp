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

#include <cmath>
#include <limits>
 
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>

#include "Assist/Basics/commonTypedefs.h"

#include "Assist/Mathematics/statistics.h"

namespace assist
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_statistics )

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
            = mathematics::convertFullWidthHalfMaximumToStandardDeviation( fullWidthHalfMaximum );

    // Check that the computed standard deviation matches the expected value.
    BOOST_CHECK_CLOSE_FRACTION( computedStandardDeviation,
                                expectedStandardDeviation,
                                std::numeric_limits< double >::epsilon( ) );
}

//! Test computation of average dependent value within one step in data map.
BOOST_AUTO_TEST_CASE( testAverageInOneStep )
{
  using namespace assist::basics;
  using namespace assist::mathematics;

  // Declare data map and add data points.
  DoubleKeyDoubleValueMap dataMap;
  dataMap[ 0.0 ] = 1.2;
  dataMap[ 10.0 ] = 0.0;

  // Set window start and end.
  const double windowStart = 1.0;
  const double windowEnd = 9.0;

  // Compute average of step-function.
  const double average = computeStepFunctionWindowAverage( dataMap, windowStart, windowEnd );

  // Check that average is equal to dependent variable value between first and second data points.
  BOOST_CHECK_EQUAL( average, dataMap.begin( )->second );                    
}

//! Test computation of average dependent value for constant function.
BOOST_AUTO_TEST_CASE( testAverageForConstantFunction )
{
  using namespace basics;
  using namespace mathematics;

  // Declare data map and add data points.
  DoubleKeyDoubleValueMap dataMap;
  dataMap[ 5.4 ] = 12.0;
  dataMap[ 11.2 ] = 12.0;
  dataMap[ 23.6 ] = 12.0;
  dataMap[ 42.7 ] = 12.0;
  dataMap[ 47.9 ] = 12.0;

  // Set window start and end.
  const double windowStart = 8.0;
  const double windowEnd = 27.5;

  // Compute average of step-function.
  const double average = computeStepFunctionWindowAverage( dataMap, windowStart, windowEnd );

  // Check that average is equal to the constant function value.
  BOOST_CHECK_CLOSE_FRACTION( average, dataMap.begin( )->second, 1.0e-15 );                    
}

//! Test computation of average dependent value for single step function.
BOOST_AUTO_TEST_CASE( testAverageForSingleStepFunction )
{
  using namespace basics;
  using namespace mathematics;

  // Declare data map and add data points.
  DoubleKeyDoubleValueMap dataMap;
  dataMap[ 2.0 ] = 2.5;
  dataMap[ 6.0 ] = 7.5;
  dataMap[ 10.0 ] = 12.5;

  // Set window start and end.
  const double windowStart = 4.0;
  const double windowEnd = 8.0;

  // Compute average of step-function.
  const double average = computeStepFunctionWindowAverage( dataMap, windowStart, windowEnd );

  // Check that average is equal to the expected value.
  BOOST_CHECK_CLOSE_FRACTION( average, 5.0, 1.0e-15 );                    
}

//! Test computation of average dependent value for window covering two points.
BOOST_AUTO_TEST_CASE( testAverageForWindowOnTwoPointsFunction )
{
  using namespace basics;
  using namespace mathematics;

  // Declare data map and add data points.
  DoubleKeyDoubleValueMap dataMap;
  dataMap[ 2.0 ] = 2.5;
  dataMap[ 6.0 ] = 7.5;

  // Set window start and end.
  const double windowStart = 2.0;
  const double windowEnd = 6.0;

  // Compute average of step-function.
  const double average = computeStepFunctionWindowAverage( dataMap, windowStart, windowEnd );

  // Check that average is equal to the expected value.
  BOOST_CHECK_CLOSE_FRACTION( average, 2.5, 1.0e-15 );                    
}

//! Test computation of average dependent value for arbitrary step function.
BOOST_AUTO_TEST_CASE( testAverageForArbitraryStepFunction )
{
  using namespace basics;
  using namespace mathematics;

  // Declare data map and add data points.
  DoubleKeyDoubleValueMap dataMap;
  dataMap[ 0.0 ] = 1.0;
  dataMap[ 1.0 ] = 3.0;
  dataMap[ 1.5 ] = 0.5;
  dataMap[ 3.0 ] = 2.0;
  dataMap[ 4.0 ] = 4.0;
  dataMap[ 5.5 ] = 3.0;

  // Set window start and end.
  const double windowStart = 1.25;
  const double windowEnd = 4.5;

  // Compute average of step-function.
  const double average = computeStepFunctionWindowAverage( dataMap, windowStart, windowEnd );

  // Check that average is equal to the expected value.
  BOOST_CHECK_CLOSE_FRACTION( average, 1.6923076923076923, 1.0e-15 );                    
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace assist
