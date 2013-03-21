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

#include <fstream>
#include <stdexcept>

#include <boost/algorithm/string.hpp>
#include <boost/exception/all.hpp>
#include <boost/iostreams/filtering_stream.hpp>

#include <TudatCore/InputOutput/streamFilters.h>

#include "Assist/InputOutput/basicInputOutput.h"

namespace assist
{
namespace input_output
{

//! Check number of input arguments.
void checkNumberOfInputArguments( const int numberOfInputArguments,
                                  const int requiredNumberOfInputArguments )
{
    // Check that an input data file has been provided; else throw and error.
    if ( numberOfInputArguments < requiredNumberOfInputArguments )
    {
        boost::throw_exception(
                    boost::enable_error_info(
                        std::runtime_error(
                            "Error: too few arguments provided." ) ) );
    }

    // Check that there are no stray arguments.
    if ( numberOfInputArguments > requiredNumberOfInputArguments )
    {
        boost::throw_exception(
                    boost::enable_error_info(
                        std::runtime_error(
                            "Error: too many arguments provided." ) ) );
    }
}

//! Read in input file and filters out comment lines.
std::string readAndFilterInputFile( const std::string& inputFileName, const char commentCharacter )
{
    // Create input file stream.
    std::ifstream inputFileStream( inputFileName.c_str( ) );

    // Declare filtered data string.
    std::string unfilteredData;

    // Declare line data string.
    std::string line;

    // Read input file line-by-line and store in unfilteredData.
    if ( inputFileStream.is_open( ) )
    {
        while ( std::getline( inputFileStream, line ) )
        {
            if ( !line.empty( ) )
            {
                unfilteredData += line + "\n";
            }
        }
    }

    // Close input file.
    inputFileStream.close( );

    // Create filter processor to filter out comment lines.
    boost::iostreams::filtering_ostream filterProcessor;

    // Add remove comment lines filter.
    filterProcessor.push( tudat::input_output::stream_filters::RemoveComment( commentCharacter ) );

    // Create filtered data string.
    std::string filteredData;

    // Last step in the chain; store the resulting string in filteredData.
    filterProcessor.push( boost::iostreams::back_inserter( filteredData ) );

    // Push in unfiltered data.
    filterProcessor << unfilteredData;

    // Make sure the data is processed by the chain.
    filterProcessor.flush( );

    // Trim all stray characters.
    boost::trim( filteredData );

    // Return filtered data string.
    return filteredData;
}

} // namespace input_output
} // namespace assist
