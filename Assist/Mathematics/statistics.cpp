/*    
 *    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *    See COPYING for license details.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      130923    K. Kumar          File created (code migrated).
 *
 *    References
 *
 *    Notes
 *
 */

#include "Assist/Mathematics/statistics.h"

namespace assist
{
namespace mathematics
{

//! Compute step-function window average.
double computeStepFunctionWindowAverage( const basics::DoubleKeyDoubleValueMap& dataMap,
                                         const double lowerBound, const double upperBound )
{
    using namespace basics;

    // Set iterator to start of window.
    DoubleKeyDoubleValueMap::const_iterator iteratorStart = dataMap.lower_bound( lowerBound );

    // Set iterator to end of window.
    DoubleKeyDoubleValueMap::const_iterator iteratorEnd = dataMap.lower_bound( upperBound );
    std::advance( iteratorEnd, -1 );

    // Declare average value of dependent variable.
    double average = 0.0;

    // Set iterator to one element before start of window, if the start of the window is not the
    // first element in the map.
    DoubleKeyDoubleValueMap::const_iterator iteratorOneBeforeStart = iteratorStart;
    if ( iteratorStart != dataMap.begin( ) )
    {
        std::advance( iteratorOneBeforeStart, -1 );
    }

    // Check if the iterators for the start and end of window are reversed in order, in terms of
    // independent value. This means that the window occurs within one step in the data map.
    if ( iteratorStart->first > iteratorEnd->first )
    {
        // Set average to start value.
        average = iteratorOneBeforeStart->second;
    }    

    // Else, compute the weighted average within the specified window.
    else
    {
        // Add contribution to first moment from values between start of window and one element
        // before the start.
        double firstMoment = ( iteratorStart->first - lowerBound ) 
            * iteratorOneBeforeStart->second;      

        // Declare iterator to next element in window.
        DoubleKeyDoubleValueMap::const_iterator iteratorNext;  

        // Loop through the window to compute contributions to the first moment.
        for ( DoubleKeyDoubleValueMap::const_iterator iteratorDataPoint
              = iteratorStart; iteratorDataPoint != iteratorEnd; iteratorDataPoint++ )
        {
            // Set iterator to next data point in window.
            iteratorNext = iteratorDataPoint;
            std::advance( iteratorNext, 1 );

            // Add contribution to first moment.
            firstMoment += ( iteratorNext->first - iteratorDataPoint->first )
                * iteratorDataPoint->second;
        }                                    

        // Compute contribution to the first moment for the end of the window.
        firstMoment += ( upperBound - iteratorEnd->first ) * iteratorEnd->second;

        // Compute average.
        average = firstMoment / ( upperBound - lowerBound );
    }

    // Return the average over the window window.
    return average;    
}

} // namespace mathematics
} // namespace assist