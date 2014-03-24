/*    
 *    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *    See COPYING for license details.
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
 * \param julianDays Julian days to convert.
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