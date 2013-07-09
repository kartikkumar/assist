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
