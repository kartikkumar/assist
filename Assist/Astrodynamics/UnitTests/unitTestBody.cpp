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
 *
 */

#define BOOST_TEST_MAIN

#include <string>

#include <boost/make_shared.hpp>
#include <boost/test/unit_test.hpp>

#include <TudatCore/Basics/testMacros.h>

#include <Tudat/Mathematics/BasicMathematics/linearAlgebraTypes.h>

#include "Assist/Astrodynamics/body.h"

namespace assist
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_body )

//! Test implementation of  body containing 3D state (position, velocity) and time.
BOOST_AUTO_TEST_CASE( testBodyCreationAndUpdatingWithTime )
{
    // Set name of body.
    std::string bodyName = "testBody";

    // Set initial state of body.
    tudat::basic_mathematics::Vector6d initialState
            = ( Eigen::VectorXd( 6 ) << 1.1, 2.2, 3.3, -4.4, -5.5, -6.6 ).finished( );

    // Set updated state of body.
    tudat::basic_mathematics::Vector6d updatedState
            = ( Eigen::VectorXd( 6 ) << 0.2, -0.4, 0.6, 6.5, 4.3, -12.1 ).finished( );

    // Set initial time.
    const double initialTime = 2.45;

    // Set updated time.
    const double updatedTime = 4.6;

    // Create Body object.
    const astrodynamics::BodyPointer testBody
            = boost::make_shared< astrodynamics::Body >( bodyName, initialState, initialTime );

    // Check that Body object is initialized as expected.
    BOOST_CHECK_EQUAL( testBody->getBodyName( ), bodyName );

    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentState( ),  initialState )
                BOOST_CHECK_EQUAL( testBody->getCurrentState( ).coeff( row, col ),
                                   initialState.coeff( row, col ) );
    }

    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentPosition( ), initialState.segment( 0, 3 ) )
                BOOST_CHECK_EQUAL( testBody->getCurrentPosition( ).coeff( row, col ),
                                   initialState.segment( 0, 3 ).coeff( row, col ) );
    }

    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentVelocity( ), initialState.segment( 3, 3 ) )
                BOOST_CHECK_EQUAL( testBody->getCurrentVelocity( ).coeff( row, col ),
                                   initialState.segment( 3, 3 ).coeff( row, col ) );
    }

    BOOST_CHECK_EQUAL( testBody->getCurrentTime( ), initialTime );

    // Update state and time stored in Body object.
    testBody->setCurrentTimeAndState( updatedState, updatedTime );

    // Check that Body object is updated as expected.
    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentState( ), updatedState )
                BOOST_CHECK_EQUAL( testBody->getCurrentState( ).coeff( row, col ),
                                   updatedState.coeff( row, col ) );
    }

    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentPosition( ), updatedState.segment( 0, 3 ) )
                BOOST_CHECK_EQUAL( testBody->getCurrentPosition( ).coeff( row, col ),
                                   updatedState.segment( 0, 3 ).coeff( row, col ) );
    }

    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentVelocity( ), updatedState.segment( 3, 3 ) )
                BOOST_CHECK_EQUAL( testBody->getCurrentVelocity( ).coeff( row, col ),
                                   updatedState.segment( 3, 3 ).coeff( row, col ) );
    }

    BOOST_CHECK_EQUAL( testBody->getCurrentTime( ), updatedTime );
}

//! Test implementation of  body containing 3D state (position, velocity) and no time.
BOOST_AUTO_TEST_CASE( testBodyCreationAndUpdatingWithoutTime )
{
    // Set name of body.
    std::string bodyName = "testBody";

    // Set initial state of body.
    tudat::basic_mathematics::Vector6d initialState
            = ( Eigen::VectorXd( 6 ) << 1.1, 2.2, 3.3, -4.4, -5.5, -6.6 ).finished( );

    // Set updated state of body.
    tudat::basic_mathematics::Vector6d updatedState
            = ( Eigen::VectorXd( 6 ) << 0.2, -0.4, 0.6, 6.5, 4.3, -12.1 ).finished( );

    // Create Body object.
    const astrodynamics::BodyPointer testBody
            = boost::make_shared< astrodynamics::Body >( bodyName, initialState );

    // Check that Body object is initialized as expected.
    BOOST_CHECK_EQUAL( testBody->getBodyName( ), bodyName );

    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentState( ),  initialState )
                BOOST_CHECK_EQUAL( testBody->getCurrentState( ).coeff( row, col ),
                                   initialState.coeff( row, col ) );
    }

    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentPosition( ), initialState.segment( 0, 3 ) )
                BOOST_CHECK_EQUAL( testBody->getCurrentPosition( ).coeff( row, col ),
                                   initialState.segment( 0, 3 ).coeff( row, col ) );
    }

    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentVelocity( ), initialState.segment( 3, 3 ) )
                BOOST_CHECK_EQUAL( testBody->getCurrentVelocity( ).coeff( row, col ),
                                   initialState.segment( 3, 3 ).coeff( row, col ) );
    }

    BOOST_CHECK_EQUAL( testBody->getCurrentTime( ), 0.0 );

    // Update state and time stored in Body object (time should remain as 0.0).
    testBody->setCurrentTimeAndState( updatedState );

    // Check that Body object is updated as expected.
    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentState( ), updatedState )
                BOOST_CHECK_EQUAL( testBody->getCurrentState( ).coeff( row, col ),
                                   updatedState.coeff( row, col ) );
    }

    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentPosition( ), updatedState.segment( 0, 3 ) )
                BOOST_CHECK_EQUAL( testBody->getCurrentPosition( ).coeff( row, col ),
                                   updatedState.segment( 0, 3 ).coeff( row, col ) );
    }

    {
        TUDAT_CHECK_MATRIX_BASE( testBody->getCurrentVelocity( ), updatedState.segment( 3, 3 ) )
                BOOST_CHECK_EQUAL( testBody->getCurrentVelocity( ).coeff( row, col ),
                                   updatedState.segment( 3, 3 ).coeff( row, col ) );
    }

    BOOST_CHECK_EQUAL( testBody->getCurrentTime( ), 0.0 );
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace assist
