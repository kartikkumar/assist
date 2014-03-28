/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    All rights reserved.
 *    See http://bit.ly/1jern3m for license details.
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

/*
 *    The functions in this file serve as boiler plate code to overload operators for 
 *    classes/structs.
 */