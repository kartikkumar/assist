/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    All rights reserved.
 *    See http://bit.ly/1jern3m for license details.
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