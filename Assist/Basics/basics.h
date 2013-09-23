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
 *      130923    K. Kumar          Migrated functions to other parts of library.
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

#include <string>

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

} // namespace basics
} // namespace assist

#endif // ASSIST_BASICS_H
