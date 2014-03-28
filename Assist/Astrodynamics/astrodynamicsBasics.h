/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    All rights reserved.
 *    See http://bit.ly/1jern3m for license details.
 */

#ifndef ASSIST_ASTRODYNAMICS_BASICS_H
#define ASSIST_ASTRODYNAMICS_BASICS_H

#include <TudatCore/Astrodynamics/BasicAstrodynamics/physicalConstants.h> 
#include <TudatCore/Mathematics/BasicMathematics/mathematicalConstants.h> 

namespace assist
{
namespace astrodynamics
{

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

} // namespace astrodynamics
} // namespace assist

#endif // ASSIST_ASTRODYNAMICS_BASICS_H