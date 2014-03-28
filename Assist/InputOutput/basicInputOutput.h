/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    All rights reserved.
 *    See http://bit.ly/1jern3m for license details.
 */

#ifndef ASSIST_BASIC_INPUT_OUTPUT_H
#define ASSIST_BASIC_INPUT_OUTPUT_H

#include <string>

namespace assist
{
namespace input_output
{

//! Check number of input arguments.
/*!
 * Checks if number of input arguments is as required. By default, the requirement is 1 argument.
 * Throws exception if the number of input arguments isn't as required. This function can be used
 * to check whether the number of input arguments provided by a user when calling an application is
 * as required.
 * \param numberOfInputArguments Number of input arguments passed.
 * \param requiredNumberOfInputArguments Number of input arguments required.
 */
void checkNumberOfInputArguments( const int numberOfInputArguments,
                                  const int requiredNumberOfInputArguments = 1 );

//! Read in input file and filters out comment lines.
/*!
 * Reads in an input file (ASCII) and filters out comment lines.
 * \param inputFileName input file name.
 * \param commentCharacter Comment character used to denote comment lines
 *          (default is taken as '#').
 * \return filteredData Filtered data as string.
 */
std::string readAndFilterInputFile( const std::string& inputFileName,
                                    const char commentCharacter = '#' );

} // namespace input_output
} // namespace assist

#endif // ASSIST_BASIC_INPUT_OUTPUT_H
