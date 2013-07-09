/*    
 *    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *    See COPYING for license details.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      130211    K. Kumar          File created; migrated code from MabSimulations project.
 *      130217    K. Kumar          Added functions extracted from
 *                                  stochasticMigrationDatabaseGenerator application in
 *                                  StochasticMigration project.
 *
 *    References
 *      Wikipedia. Full width at half maximum,
 *          http://en.wikipedia.org/wiki/Full_width_at_half_maximum, last accessed: 8th Mar, 2013.
 *
 *    Notes
 *      A unit test is needed for the getAssistRootPath() function.
 *
 */

#ifndef ASSIST_BASICS_H
#define ASSIST_BASICS_H

#include <cmath>
#include <string>

#include <TudatCore/Astrodynamics/BasicAstrodynamics/physicalConstants.h>
#include <TudatCore/Mathematics/BasicMathematics/mathematicalConstants.h>

namespace assist
{
namespace basics
{

//! Get root-path for Assist directory.
/*!
 * Returns root-path corresponding with root-directory of Assist as a string with
 * trailing slash included.
 * \return Assist root-path.
 */
static inline std::string getAssistRootPath( )
{
#ifdef ASSIST_CUSTOM_ROOT_PATH
    return std::string( ASSIST_CUSTOM_ROOT_PATH );
#else
    // Declare file path string assigned to filePath.
    // __FILE__ only gives the absolute path in the header file!
    std::string filePath_( __FILE__ );

    // Strip filename from temporary string and return root-path string.
    return filePath_.substr( 0, filePath_.length( ) -
                                std::string( "Basics/basics.h" ).length( ) );
#endif
}

//! Convert Full-Width Half-Maximum (FWHM) to standard deviation.
/*!
 * Converts a FWHM value to standard deviation given by the definition of FWHM for a normal
 * distribution (Wikipedia, 2013).
 * \param fullWidthHalfMaximum FWHM to convert to standard deviation.
 * \return Standard deviation corresponding to FWHM given as input.
 */
inline double convertFullWidthHalfMaximumToStandardDeviation( const double fullWidthHalfMaximum )
{
    return fullWidthHalfMaximum / ( 2.0 * std::sqrt( 2.0 * std::log( 2.0 ) ) );
}

//! Compute mass of sphere of uniform density.
/*!
 * Computes mass of sphere of given uniform bulk density.
 * \param sphereRadius Radius of sphere [m].
 * \param bulkDensity Uniform bulk density of sphere [khg m^-3].
 * \return Mass of sphere of uniform density [kg]
 */
inline double computeMassOfSphere( const double sphereRadius, const double bulkDensity )
{
    return sphereRadius * sphereRadius * sphereRadius
            * 4.0 / 3.0 * tudat::basic_mathematics::mathematical_constants::PI * bulkDensity;
}

//! Compute gravitational parameter of body of given mass.
/*!
 * Computes gravitational parameter of a body of specified mass.
 * \param massOfBody Mass of body [kg]
 * \return Gravitational parameter of body.
 */
inline double computeGravitationalParameter( const double massOfBody )
{
    return massOfBody * tudat::basic_astrodynamics::physical_constants::GRAVITATIONAL_CONSTANT;
}

} // namespace basics
} // namespace assist

#endif // ASSIST_BASICS_H
