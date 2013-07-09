/*    
 *    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *    See COPYING for license details.
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
