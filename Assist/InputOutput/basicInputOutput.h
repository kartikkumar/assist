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
