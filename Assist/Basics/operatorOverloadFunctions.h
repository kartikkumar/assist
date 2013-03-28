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
 *      130323    K. Kumar          File created.
 *
 *    References
 *
 *    Notes
 *		The functions in this file serve as boiler plate code to overload operators for 
 *		classes/structs.
 *
 */


#ifndef ASSIST_OPERATOR_OVERLOAD_FUNCTIONS_H
#define ASSIST_OPERATOR_OVERLOAD_FUNCTIONS_H

namespace assist
{
namespace basics
{

//
// Define non-const versions of boiler plate functions.
//

//! Overload == operator.
template< typename DataStruct >
inline bool operator==( DataStruct& dataStruct1, DataStruct& dataStruct2 )
{
    return operator==( const_cast< DataStruct& >( dataStruct1 ), 
    	const_cast< DataStruct& >( dataStruct2 ) );
}

// //! Overload != operator.
// template< typename DataStruct >
// inline bool operator!=( DataStruct& dataStruct1, DataStruct& dataStruct2 )
// {
//     return !operator==( dataStruct1, dataStruct2 );
// }

// //! Overload > operator.
// template< typename DataStruct >
// inline bool operator>( DataStruct& dataStruct1, DataStruct& dataStruct2 )
// {
//     return operator<( dataStruct1, dataStruct1 );
// }

//
// Define const versions of boiler plate functions.
//

// //! Overload != operator.
// template< typename DataStruct >
// inline bool operator!=( const DataStruct& dataStruct1, const DataStruct& dataStruct2 )
// {
//     return operator!=( static_cast< DataStruct& >( dataStruct1 ), 
//     	static_cast< DataStruct& >( dataStruct2 ) );
// }

// //! Overload <= operator.
// inline bool operator<=( const DataStruct& dataStruct1,
//                  const DataStruct& dataStruct2 );

// //! Overload >= operator.
// inline bool operator>=( const DataStruct& dataStruct1,
//                  const DataStruct& dataStruct2 );

// //! Overload == operator for shared-pointers.
// inline bool operator==( const DataStructPointer& dataStruct1,
//                  const DataStructPointer& dataStruct2 );

// //! Overload != operator for shared-pointers.
// inline bool operator!=( const DataStructPointer& dataStruct1,
//                  const DataStructPointer& dataStruct2 );

// //! Overload < operator for shared-pointers.
// inline bool operator<( const DataStructPointer& dataStruct1,
//                 const DataStructPointer& dataStruct2 );

// //! Overload > operator for shared-pointers.
// inline bool operator>( const DataStructPointer& dataStruct1,
//                 const DataStructPointer& dataStruct2 );

// //! Overload <= operator for shared-pointers.
// inline bool operator<=( const DataStructPointer& dataStruct1,
//                  const DataStructPointer& dataStruct2 );

// //! Overload >= operator for shared-pointers.
// inline bool operator>=( const DataStructPointer& dataStruct1,
//                  const DataStructPointer& dataStruct2 );

} // namespace basics
} // namespace assist

#endif // ASSIST_OPERATOR_OVERLOAD_FUNCTIONS_H