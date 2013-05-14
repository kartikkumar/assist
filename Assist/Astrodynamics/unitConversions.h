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
 *      130211    K. Kumar          File created; migrated code from basics.h.
 *      130329    K. Kumar          Added Julian days <-> seconds conversions.
 *
 *    References
 *
 *    Notes
 *
 */

#include <TudatCore/Astrodynamics/BasicAstrodynamics/physicalConstants.h>

namespace assist
{
namespace astrodynamics
{

//! Convert Julian years to seconds.
/*!
 * Converts Julian years to seconds.
 * \param julianYears Julian years to convert.
 * \return Number of seconds corresponding to Julian years given as input.
 */
inline double convertJulianYearsToSeconds( const double julianYears )
{
    return julianYears * tudat::basic_astrodynamics::physical_constants::JULIAN_YEAR;
}

//! Convert seconds to Julian years.
/*!
 * Converts seconds to Julian years.
 * \param seconds Seconds to convert.
 * \return Number of Julian years corresponding to seconds given as input.
 */
inline double convertSecondsToJulianYears( const double seconds )
{
    return seconds / tudat::basic_astrodynamics::physical_constants::JULIAN_YEAR;
}	


//! Convert Julian days to seconds.
/*!
 * Converts Julian days to seconds.
 * \param julianYears Julian days to convert.
 * \return Number of seconds corresponding to Julian days given as input.
 */
inline double convertJulianDaysToSeconds( const double julianDays )
{
    return julianDays * tudat::basic_astrodynamics::physical_constants::JULIAN_DAY;
}

//! Convert seconds to Julian days.
/*!
 * Converts seconds to Julian days.
 * \param seconds Seconds to convert.
 * \return Number of Julian days corresponding to seconds given as input.
 */
inline double convertSecondsToJulianDays( const double seconds )
{
    return seconds / tudat::basic_astrodynamics::physical_constants::JULIAN_DAY;
}   


} // namespace astrodynamics
} // namespace assist