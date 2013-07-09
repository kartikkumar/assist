/*    
 *    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *    See COPYING for license details.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      130323    K. Kumar          File created.
 *      130328    K. Kumar          Completed boiler-plate functions.
 *
 *    References
 *
 *    Notes
 *      The functions in this file serve as boiler plate code to overload operators for 
 *      classes/structs.
 *
 */


#ifndef ASSIST_OPERATOR_OVERLOAD_FUNCTIONS_H
#define ASSIST_OPERATOR_OVERLOAD_FUNCTIONS_H

#include <boost/shared_ptr.hpp>

namespace assist
{
namespace basics
{
namespace operator_overload_functions
{

//
// Overload operators for pass-by-reference.
//

//! Overload != operator.
template< typename DataStruct >
inline bool operator!=( const DataStruct& dataStruct1, const DataStruct& dataStruct2 )
{
    return !( dataStruct1 == dataStruct2 );
}   

//! Overload > operator.
template< typename DataStruct >
inline bool operator>( const DataStruct& dataStruct1, const DataStruct& dataStruct2 )
{
    return ( !( dataStruct1 < dataStruct2 ) || !( dataStruct1 == dataStruct1 ) );
}

//! Overload <= operator.
template< typename DataStruct >
inline bool operator<=( const DataStruct& dataStruct1, const DataStruct& dataStruct2 )
{
    return ( ( dataStruct1 < dataStruct2 ) || ( dataStruct1 == dataStruct1 ) );
}

//! Overload >= operator.
template< typename DataStruct >
inline bool operator>=( const DataStruct& dataStruct1, const DataStruct& dataStruct2 )
{
    return !( dataStruct1 < dataStruct1 );
}

} // namespace operator_overload_functions
} // namespace basics
} // namespace assist

#endif // ASSIST_OPERATOR_OVERLOAD_FUNCTIONS_H