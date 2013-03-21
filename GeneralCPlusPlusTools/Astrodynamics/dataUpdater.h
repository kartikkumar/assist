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
 *      120817    K. Kumar          File created; migrated code from
 *                                  MabSimulations/Astrodynamics/body.h
 *    References
 *
 *    Notes
 *
 */

#ifndef GENERAL_C_PLUS_PLUS_TOOLS_DATA_UPDATER_H
#define GENERAL_C_PLUS_PLUS_TOOLS_DATA_UPDATER_H

#include <boost/shared_ptr.hpp>

#include "GeneralCPlusPlusTools/Astrodynamics/body.h"

#include "GeneralCPlusPlusTools/Basics/commonTypedefs.h"

namespace general_c_plus_plus_tools
{
namespace astrodynamics
{

//! Data updater class.
/*!
 * Essentially, this class serves to provide a wrapper for an update()-function that is called by
 * the composite state derivative model in Tudat. It provides an interface to update a composition
 * of two states, carried by Body objects. The current time associated with each state is also
 * updated.
 * \sa CompositeStateDerivativeModel, Body.
 */
class DataUpdater
{
public:

    //! Constructor taking shared-pointers to bodies.
    /*!
     * Constructor taking shared-pointers to bodies, which are used internally to update the times
     * and states stored in these bodies. This is used in conjunction with the composite state
     * derivative model in Tudat. The order in which the bodies are passed must be respected!
     * \param aBody1 Shared-pointer to body1.
     * \param aBody2 Shared-pointer to body2.
     */
    DataUpdater( const BodyPointer aBody1, const BodyPointer aBody2 )
        : body1( aBody1 ),
          body2( aBody2 )
    { }

    //! Update time and composite state.
    /*!
     * Updates the stored time and composite state information in body1 and body1 and body2.
     * Essentially, this function serves as a means to disassemble the composite state
     * and accordingly update the current state of the two bodies. For this to work, the
     * order of the states in the composite state MUST be respected where ever the composite
     * state is used.
     * \param time Current time.
     * \param compositeState Current composite state (represented as vector of 12 elements).
     */
    void updateTimeAndCompositeState( const double time, const basics::Vector12d& compositeState )
    {
        body1->setCurrentTimeAndState( compositeState.segment( 0, 6 ), time  );
        body2->setCurrentTimeAndState( compositeState.segment( 6, 6 ), time  );
    }

protected:
private:

    //! Shared-pointer to body1.
    const BodyPointer body1;

    //! Shared-pointer to body2.
    const BodyPointer body2;
};

//! Typedef for a shared-pointer to a DataUpdater object.
typedef boost::shared_ptr< DataUpdater > DataUpdaterPointer;

} // namespace astrodynamics
} // namespace general_c_plus_plus_tools

#endif // GENERAL_C_PLUS_PLUS_TOOLS_DATA_UPDATER_H
