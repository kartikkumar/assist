 #    Copyright (c) 2010-2013, Delft University of Technology
 #    All rights reserved.
 #
 #    Redistribution and use in source and binary forms, with or without modification, are
 #    permitted provided that the following conditions are met:
 #      - Redistributions of source code must retain the above copyright notice, this list of
 #        conditions and the following disclaimer.
 #      - Redistributions in binary form must reproduce the above copyright notice, this list of
 #        conditions and the following disclaimer in the documentation and/or other materials
 #        provided with the distribution.
 #      - Neither the name of the Delft University of Technology nor the names of its contributors
 #        may be used to endorse or promote products derived from this software without specific
 #        prior written permission.
 #
 #    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
 #    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 #    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 #    COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 #    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 #    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 #    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 #    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 #    OF THE POSSIBILITY OF SUCH DAMAGE.
 #
 #    Changelog
 #      YYMMDD    Author            Comment
 #      110820    S.M. Persson      File created.
 #      130211    K. Kumar          Adapted file to work with GeneralTools/Basics.
 #      130320    K. Kumar          Renamed static library to assist*. 
 #
 #    References
 #
 #    Notes
 #

# Set source files.
set(INPUTOUTPUT_SOURCES
  "${SRCROOT}${INPUTOUTPUTDIR}/basicInputOutput.cpp"
)

# Set header files.
set(INPUTOUTPUT_HEADERS
  "${SRCROOT}${INPUTOUTPUTDIR}/basicInputOutput.h"
)

# Add static library.
add_library(assist_input_output STATIC ${INPUTOUTPUT_SOURCES} ${INPUTOUTPUT_HEADERS})
setup_library_target(assist_input_output "${SRCROOT}${INPUTOUTPUTDIR}")

# Add unit tests.
add_executable(test_Basic_Input_Output "${SRCROOT}${INPUTOUTPUTDIR}/UnitTests/unitTestBasicInputOutput.cpp")
setup_unit_test_target(test_Basic_Input_Output "${SRCROOT}${INPUTOUTPUTDIR}")
target_link_libraries(test_Basic_Input_Output assist_input_output assist_basics ${TUDAT_CORE_LIBRARIES} ${Boost_LIBRARIES})

#add_executable(test_CommonTypedefs "${SRCROOT}${INPUTOUTPUTDIR}/UnitTests/unitTestCommonTypedefs.cpp")
#setup_unit_test_target(test_CommonTypedefs "${SRCROOT}${INPUTOUTPUTDIR}")
#target_link_libraries(test_CommonTypedefs assist_input_output ${Boost_LIBRARIES})
