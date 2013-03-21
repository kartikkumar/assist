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
 *      130211    K. Kumar          File created; migrated code from MabSimulations project.
 *
 *    References
 *
 *    Notes
 *
 */

#ifndef ASSIST_COMMON_TYPEDEFS_H
#define ASSIST_COMMON_TYPEDEFS_H

#include <map>
#include <utility>

#include <Eigen/Core>

#include <Tudat/Mathematics/BasicMathematics/linearAlgebraTypes.h>

namespace assist
{
namespace basics
{

//! Typedef for Eigen Vector of length 12.
typedef Eigen::Matrix< double, 12, 1 > Vector12d;

//! Typdef for double-key, double-value map.
typedef std::map< double, double > DoubleKeyDoubleValueMap;

//! Typedef for double-key, double-value pair.
typedef std::pair< double, double > DoubleKeyDoubleValuePair;

//! Typedef for double-key, Vector6d-value map.
typedef std::map< double, Eigen::Vector3d > DoubleKeyVector3dValueMap;

//! Typedef for double-key, Vector3d-value map.
typedef std::map< double, tudat::basic_mathematics::Vector6d > DoubleKeyVector6dValueMap;

} // namespace basics
} // namespace assist

#endif // ASSIST_COMMON_TYPEDEFS_H
