/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    All rights reserved.
 *    See http://bit.ly/1jern3m for license details.
 */

#ifndef ASSIST_INPUT_OUTPUT_H
#define ASSIST_INPUT_OUTPUT_H

#include <string>

namespace assist
{
namespace input_output
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
                                std::string( "InputOutput/rootPath.h" ).length( ) );
#endif
}

} // namespace input_output
} // namespace assist

#endif // ASSIST_INPUT_OUTPUT_H
