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
 *      130211    K. Kumar          File created.
 *
 *    References
 *
 *    Notes
 *
 */

#define BOOST_TEST_MAIN

#include <iostream>
#include <string>
#include <sstream>

#include <boost/test/unit_test.hpp>

#include "Assist/Basics/basics.h"

#include "Assist/InputOutput/basicInputOutput.h"

namespace assist
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_basic_input_output )

//! Test implementation of function that checks number of input arguments provided.
BOOST_AUTO_TEST_CASE( testCheckOnNumberOfInputArguments )
{
    // This function checks if the number of input arguments provided is as required.

    // Test 1: Check no error is thrown if the number of arguments passed (1) is as required by
    //         default (1).
    {
        // Set flag indicating that required number of arguments is matched to true.
        bool isRequiredInputArguments = true;

        // Call function.
        try
        {
            input_output::checkNumberOfInputArguments( 1 );
        }

        // Catch any possible run-time errors thrown.
        catch( std::runtime_error& error )
        {
            // If a run-time error is thrown, set flag to false.
            isRequiredInputArguments = false;
        }

        // Check that no run-time error was thrown.
        BOOST_CHECK( isRequiredInputArguments );
    }

    // Test 2: Check no error is thrown if the number of arguments passed (2) is as required (2).
    {
        // Set flag indicating that required number of arguments is matched to true.
        bool isRequiredInputArguments = true;

        // Call function.
        try
        {
            input_output::checkNumberOfInputArguments( 2, 2 );
        }

        // Catch any possible run-time errors thrown.
        catch( std::runtime_error& error )
        {
            // If a run-time error is thrown, set flag to false.
            isRequiredInputArguments = false;
        }

        // Check that no run-time error was thrown.
        BOOST_CHECK( isRequiredInputArguments );
    }

    // Test 3: Check error is thrown if the number of arguments (2) passed is not as
    //         required by default (1).
    {
        // Set flag indicating that required number of arguments is matched to true.
        bool isRequiredInputArguments = true;

        // Call function.
        try
        {
            input_output::checkNumberOfInputArguments( 2 );
        }

        // Catch any possible run-time errors thrown.
        catch( std::runtime_error& error )
        {
            // If a run-time error is thrown, set flag to false.
            isRequiredInputArguments = false;
        }

        // Check that no run-time error was thrown.
        BOOST_CHECK( !isRequiredInputArguments );
    }

    // Test 4: Check error is thrown if the number of arguments (3) passed is not as
    //         required (4).
    {
        // Set flag indicating that required number of arguments is matched to true.
        bool isRequiredInputArguments = true;

        // Call function.
        try
        {
            input_output::checkNumberOfInputArguments( 3, 4 );
        }

        // Catch any possible run-time errors thrown.
        catch( std::runtime_error& error )
        {
            // If a run-time error is thrown, set flag to false.
            isRequiredInputArguments = false;
        }

        // Check that no run-time error was thrown.
        BOOST_CHECK( !isRequiredInputArguments );
    }
}

//! Test implementation of function used to read and filter input files.
BOOST_AUTO_TEST_CASE( testInputFileReadAndFilterFunction )
{
    // Read test input file, and check that the filtered string return is as expected.

    // Test 1: Check that the function returns the correct filtered string with the default comment
    //         character (#).
    {
        // Set absolute path to test input file.
        const std::string absolutePathTestInputFile
                = basics::getAssistRootPath( )
                + "/InputOutput/UnitTests/testInputFileDefaultCommentCharacter.txt";

        // Set expected filtered string.
        std::stringstream expectedFilteredString;
        expectedFilteredString << "First line that should not be filtered.\n"
                               << "Second line that should not be filtered.\n"
                               << "Last line that should not be filtered.";

        // Read and filter test input file.
        const std::string filteredString
                = input_output::readAndFilterInputFile( absolutePathTestInputFile );

        BOOST_CHECK_EQUAL( filteredString, expectedFilteredString.str( ) );
    }

    // Test 2: Check that the function returns the correct filtered string with a custom comment
    //         character (%).
    {
        // Set absolute path to test input file.
        const std::string absolutePathTestInputFile
                = basics::getAssistRootPath( )
                + "/InputOutput/UnitTests/testInputFileCustomCommentCharacter.txt";

        // Set expected filtered string.
        std::stringstream expectedFilteredString;
        expectedFilteredString << "First line that should not be filtered.\n"
                               << "Second line that should not be filtered.\n"
                               << "Last line that should not be filtered.";

        // Read and filter test input file.
        const std::string filteredString
                = input_output::readAndFilterInputFile( absolutePathTestInputFile, '%' );

        BOOST_CHECK_EQUAL( filteredString, expectedFilteredString.str( ) );
    }
}

BOOST_AUTO_TEST_SUITE_END( )

} // namespace unit_tests
} // namespace assist
