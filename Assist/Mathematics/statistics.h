/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    All rights reserved.
 *    See http://bit.ly/1jern3m for license details.
 */

#ifndef ASSIST_STATISTICS_H
#define ASSIST_STATISTICS_H

#include <cmath>

#include <Assist/Basics/commonTypedefs.h>

namespace assist
{
namespace mathematics
{

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

//! Compute step-function window average.
/*!
 * Computes weighted average value of dependent variable in a given window. The independent and
 * dependent values corresponding to the step-function described are stored in a map. The window is
 * specified as a lower and upper bound of the independent value.
 * \param dataMap Map containing independent and dependent values.
 * \param lowerBound Lower bound for window (independent variable).
 * \param upperBound Upper bound for window (independent variable).
 * \return Weighted average of step-function in given window.
 */
double computeStepFunctionWindowAverage( const basics::DoubleKeyDoubleValueMap& dataMap,
                                         const double lowerBound, const double upperBound );

} // namespace mathematics
} // namespace assist

#endif // ASSIST_STATISTICS_H 

/*
 *    References
 *      Wikipedia. Full width at half maximum,
 *          http://en.wikipedia.org/wiki/Full_width_at_half_maximum, last accessed: 8th Mar, 2013.
 */