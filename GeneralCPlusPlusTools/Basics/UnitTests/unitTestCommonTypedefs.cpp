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

#include "GeneralCPlusPlusTools/Basics/commonTypedefs.h"

namespace general_c_plus_plus_tools
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
} // namespace general_c_plus_plus_tools
