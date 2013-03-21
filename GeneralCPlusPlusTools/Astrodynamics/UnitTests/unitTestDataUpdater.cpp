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
 *      The unit tests in this file are not strictly "unit tests", but rather system tests, since
 *      they depend on the code implemented in GeneralTools/Astrodynamics/body.h.
 *
 */

#define BOOST_TEST_MAIN

#include <boost/make_shared.hpp>
#include <boost/test/unit_test.hpp>

#include <Eigen/Core>

#include <TudatCore/Basics/testMacros.h>

#include "GeneralTools/Astrodynamics/body.h"
#include "GeneralTools/Astrodynamics/dataUpdater.h"

namespace general_tools
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_data_updater )

//! Test implementation of data updater for two bodies.
BOOST_AUTO_TEST_CASE( testDataUpdater )
{
    // Declare bodies.
    astrodynamics::BodyPointer body1 = boost::make_shared< astrodynamics::Body >(
                "body1",
                ( Eigen::VectorXd( 6 ) << 1.2, 3.4, -9.7, 4.6, -5.1, -0.1 ).finished( ),
                0.0 );

    astrodynamics::BodyPointer body2  = boost::make_shared< astrodynamics::Body >(
                "body2",
                ( Eigen::VectorXd( 6 ) << -4.5, 4.4, 7.8, -0.2, 6.7, -6.9 ).finished( ),
                0.0 );

    // Declare data updater.
    astrodynamics::DataUpdaterPointer dataUpdater
            = boost::make_shared< astrodynamics::DataUpdater >( body1, body2 );

    // Set updated composite state (body1 state first, followed by body2).
    const Eigen::Matrix< double, 12, 1 > updatedCompositeState
            = ( Eigen::VectorXd( 12 ) << 6.0, -1.3, 5.8, 4.3, 2.0, -0.9,
                1.1, -2.5, -9.8, 1.2, -0.4, 1.3 ).finished( );

    // Set updated time.
    const double updatedTime = 2.4;

    // Update states and time.
    dataUpdater->updateTimeAndCompositeState( updatedTime, updatedCompositeState );

    // Check that states and time were updated correctly.
    {
        TUDAT_CHECK_MATRIX_BASE( body1->getCurrentState( ), updatedCompositeState.segment( 0, 6 ) )
                BOOST_CHECK_EQUAL( body1->getCurrentState( ).coeff( row, col ),
                                   updatedCompositeState.segment( 0, 6 ).coeff( row, col ) );
    }

    {
        TUDAT_CHECK_MATRIX_BASE( body2->getCurrentState( ), updatedCompositeState.segment( 6, 6 ) )
                BOOST_CHECK_EQUAL( body2->getCurrentState( ).coeff( row, col ),
                                   updatedCompositeState.segment( 6, 6 ).coeff( row, col ) );
    }

    BOOST_CHECK_EQUAL( body1->getCurrentTime( ), updatedTime );
    BOOST_CHECK_EQUAL( body2->getCurrentTime( ), updatedTime );
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace general_tools
