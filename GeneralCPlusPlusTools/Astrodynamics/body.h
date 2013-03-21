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
 *      120817    K. Kumar          File created.
 *      120820    K. Kumar          Completed Doxygen comments.
 *      120831    K. Kumar          Completed Doxygen comments for DataUpdater class.
 *      130211    K. Kumar          Moved to GeneralTools/Astrodynamics; removed everything other
 *                                  than Body class; wrapped code in new namespaces and updated
 *                                  include guards.
 *
 *    References
 *
 *    Notes
 *
 */

#ifndef GENERAL_C_PLUS_PLUS_TOOLS_BODY_H
#define GENERAL_C_PLUS_PLUS_TOOLS_BODY_H

#include <string>

#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include <Eigen/Core>

#include <Tudat/Mathematics/BasicMathematics/linearAlgebraTypes.h>

namespace general_c_plus_plus_tools
{
namespace astrodynamics
{

//! Body class.
/*!
 * This class functions as a container for body properties. At the moment, the state of a body can
 * be stored in this class, and accompanying set- and get-functions are provided to use in
 * conjunction with acceleration models and the Cartesian state derivative model in Tudat.
 * \sa AccelerationModel, CartesianStateDerivativeModel.
 */
class Body
{
private:

    //! Typedef for a double-returning function.
    typedef boost::function< double( ) > DoubleReturningFunction;

public:

    //! Constructor taking the body's name, current state vector, and associated current time.
    /*!
     * Constructor taking the body's name, current state vector, and associated current time
     * (which has a default of 0.0).
     * \param aBodyName Body name.
     * \param aCurrentState Current state vector of body.
     * \param aCurrenTime Current time associated with current state vector of body.
     */
    Body( const std::string& aBodyName,
          const tudat::basic_mathematics::Vector6d& aCurrentState,
          const double aCurrentTime = 0.0 )
        : bodyName( aBodyName ),
          currentPosition( aCurrentState.segment( 0, 3 ) ),
          currentState( aCurrentState ),
          currentVelocity( aCurrentState.segment( 3, 3 ) ),
          currentTime( aCurrentTime )
    { }

    //! Get body name.
    std::string getBodyName( ) { return bodyName; }

    //! Set current state and time.
    void setCurrentTimeAndState( const tudat::basic_mathematics::Vector6d& aCurrentState,
                                 const double aCurrentTime = 0.0 )
    {
        currentTime = aCurrentTime;
        currentState = aCurrentState;
        currentPosition = aCurrentState.segment( 0, 3 );
        currentVelocity = aCurrentState.segment( 3, 3 );
    }

    //! Get current time.
    double getCurrentTime( ) { return currentTime; }

    //! Get current position.
    Eigen::Vector3d getCurrentPosition( ) { return currentPosition; }

    //! Get current position.
    Eigen::Vector3d getCurrentVelocity( ) { return currentVelocity; }

    //! Get current state.
    tudat::basic_mathematics::Vector6d getCurrentState( ) { return currentState; }

protected:

private:

    //! Body name.
    const std::string bodyName;

    //! Current position vector of body.
    Eigen::Vector3d currentPosition;

    //! Current state vector of body.
    tudat::basic_mathematics::Vector6d currentState;

    //! Current velocity vector of body.
    Eigen::Vector3d currentVelocity;

    //! Current time associated with current position vector of body.
    double currentTime;
};

//! Typedef for a shared-pointer to a Body object.
typedef boost::shared_ptr< Body > BodyPointer;

} // namespace astrodynamics
} // namespace general_c_plus_plus_tools

#endif // GENERAL_C_PLUS_PLUS_TOOLS_BODY_H
