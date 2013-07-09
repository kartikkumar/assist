/*    
 *    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *    See COPYING for license details.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      130211    K. Kumar          File created.
 *
 *    References
 *
 *    Notes
 *      These tests are simply to ensure that the typedef definitions are not accidentally altered.
 *
 */

#define BOOST_TEST_MAIN

#include <map>
#include <typeinfo>
#include <utility>

#include <boost/test/unit_test.hpp>

#include <Eigen/Core>

#include "Assist/Basics/commonTypedefs.h"

namespace assist
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_common_typedefs )

//! Test definition of common typedefs.
BOOST_AUTO_TEST_CASE( testCommonTypedefs )
{
    // Check if typedefs are defined as required.
    BOOST_CHECK( typeid( basics::Vector12d ) == typeid( Eigen::Matrix< double, 12, 1 > ) );

    BOOST_CHECK( typeid( basics::DoubleKeyDoubleValueMap )
                 == typeid( std::map< double, double > ) );

    BOOST_CHECK( typeid( basics::DoubleKeyDoubleValuePair )
                 == typeid( std::pair< double, double > ) );

    BOOST_CHECK( typeid( basics::DoubleKeyVector3dValueMap )
                 == typeid( std::map< double, Eigen::Vector3d > ) );

    BOOST_CHECK( typeid( basics::DoubleKeyVector6dValueMap )
                 == typeid( std::map< double, Eigen::Matrix< double, 6, 1 > > ) );
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace assist
