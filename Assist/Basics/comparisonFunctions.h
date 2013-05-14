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
 *      130314    K. Kumar          File created.
 *      130322    K. Kumar          Corrected and updated Doxygen comments for functions.
 *
 *    References
 *
 *    Notes
 *
 */

#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

 #include "Assist/Basics/commonTypedefs.h"

#ifndef ASSIST_COMPARISON_FUNCTIONS_H
#define ASSIST_COMPARISON_FUNCTIONS_H

namespace assist
{
namespace basics
{

//! Check if a given data point is greater than a specified lower bound.
/*!
 * Checks if a given data point is greater than a lower bound specified by the user. If the data
 * point is not greater than the specified lower bound, a run-time error is thrown. Else, the data
 * point is returned by the function. This function can be used for any data type for which the "<"
 * operators is defined.
 * \param dataPoint Value of datum to be tested.
 * \param name String name of datum.
 * \param lowerBound Lower bound test data point against.
 * \return Data point if it passes the range test successfully.
 */
template< typename DataType >
inline DataType checkGreaterThan( const DataType dataPoint, const std::string name,
                                  const DataType lowerBound )
{
    if ( dataPoint < lowerBound )
    {
        std::ostringstream errorMessage;
        errorMessage << name << " is: " << dataPoint << ", which is less than " << lowerBound;
        throw std::runtime_error( errorMessage.str( ) );
    }

    return dataPoint;
}

//! Check if a given data point is less than a specified upper bound.
/*!
 * Checks if a given data point is less than an upper bound specified by the user. If the data
 * point is not less than the specified upper bound, a run-time error is thrown. Else, the data
 * point is returned by the function. This function can be used for any data type for which the ">"
 * operators is defined.
 * \param dataPoint Value of datum to be tested.
 * \param name String name of datum.
 * \param upperBound Upper bound test data point against.
 * \return Data point if it passes the range test successfully.
 */
 template< typename DataType >
inline DataType checkLessThan( const DataType dataPoint, const std::string name,
                               const DataType upperBound )
{
    if ( dataPoint > upperBound )
    {
        std::ostringstream errorMessage;
        errorMessage << name << " is: " << dataPoint << ", which is greater than " << upperBound;
        throw std::runtime_error( errorMessage.str( ) );
    }

    return dataPoint;
}

//! Check if a given data point is within the specified range.
/*!
 * Checks if a given data point is within the range specified by the lower and upper bound provided
 * by the user. If the data point is not within the range, a run-time error is thrown. Else, the
 * data point is returned by the function. This function can be used for any data type for which
 * the "<" and ">" operators are defined. This function is effectively a wrapper for a chained call
 * to the checkLessThan() and checkGreaterThan() functions.
 * \param dataPoint Value of datum to be tested.
 * \param name String name of datum.
 * \param lowerBound Lower bound in range to test data point in.
 * \param upperBound Upper bound in range to test data point in.
 * \return Data point if it passes the range test successfully.
 * \sa checkLessThan(), checkGreaterThan().
 */
template< typename DataType >
inline DataType checkInRange( const DataType dataPoint, const std::string name,
                              const DataType lowerBound, const DataType upperBound )
{
    checkLessThan( checkGreaterThan( dataPoint, name, lowerBound ), name, upperBound );
    return dataPoint;
}

//! Check if a given data point is positive.
/*!
 * Checks if a given data point is positive, by calling the checkGreaterThan() function with
 * lowerBound=0 If the data point is not positive, a run-time error is thrown. Else, the data point
 * is returned by the function. This function only makes sense when used in conjunction with whole 
 * and floating-point numbers (e.g., integers and floats, not strings).
 * \param dataPoint Value of datum to be tested.
 * \param name String name of datum.
 * \return Data point if it passes the test successfully.
* \sa checkGreaterThan().
 */
template< typename DataType >
inline DataType checkPositive( const DataType dataPoint, const std::string name )
{
    checkGreaterThan( dataPoint, name, static_cast< DataType >( 0 ) );
    return dataPoint;
}

//! Check if a given data point is negative.
/*!
 * Checks if a given data point is negative, by calling the checkLessThan() function with
 * upperBound=0. If the data point is not negative a run-time error is thrown. Else, the data point
 * is returned by the function. This function only makes sense when used in conjunction with whole
 * and floating-point numbers (e.g., integers and floats, not strings).
 * \param dataPoint Value of datum to be tested.
 * \param name String name of datum.
 * \return Data point if it passes the test successfully.
 * \sa checkLessThan().
 */
template< typename DataType >
inline DataType checkNegative( const DataType dataPoint, const std::string name )
{
    checkLessThan( dataPoint, name, static_cast< DataType >( 0 ) );
    return dataPoint;
}

//! Functor to compare two values in a DoubleKeyDoubleValue map.
/*!
 * This functor compares two values stored in a DoubleKeyDoubleValue map. The functor returns true
 * if the first value is less than the second.
 */
class CompareDoubleKeyDoubleValueMapValues
{
public:

    //! Compare values.
    /*!
     * Compares two values, given as entries in a DoubleKeyDoubleValue map.
     * \return True if value1 is less than value2.
     */
    bool operator( )( DoubleKeyDoubleValuePair keyValuePair1,
                      DoubleKeyDoubleValuePair keyValuePair2 )
    {
        return keyValuePair1.second < keyValuePair2.second;
    }

private:
protected:
};

//! Functor to compare two values in a DoubleKeyDoubleValue map, wrt a common reference point.
/*!
 * This functor compares two values stored in a DoubleKeyDoubleValue map with respect to a common
 * reference point. The functor evaluates the Euclidean norm of both values wrt the reference.
 * The functor returns true if the first distance is closer to the reference than the
 * second.
 */
class CompareDoubleKeyDoubleValueMapRelativeDistances
{
public:

    //! Constructor taking reference.
    /*!
     * Constructor taking a reference point.
     * \param aReferencePoint Reference point.
     */
    CompareDoubleKeyDoubleValueMapRelativeDistances( const double aReferencePoint )
        : referencePoint( aReferencePoint )
    { }

    //! Compare distances wrt reference point.
    /*!
     * Compares two distances wrt to specified reference point, given as values in a
     * DoubleKeyDoubleValue map.
     * \return True if distance1 is less than distance2.
     */
    bool operator( )( DoubleKeyDoubleValuePair distance1,
                      DoubleKeyDoubleValuePair distance2 )
    {
        return std::fabs( distance1.second - referencePoint )
                < std::fabs( distance2.second - referencePoint );
    }

protected:
private:

    //! Reference point.
    const double referencePoint;
};

} // namespace basics
} // namespace assist

#endif // ASSIST_COMPARISON_FUNCTIONS_H
