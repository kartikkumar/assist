 #    Copyright (c) 2010-2014, Delft University of Technology
 #    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 #    All rights reserved.
 #    See http://bit.ly/1jern3m for license details.

# Set source files.
set(INPUTOUTPUT_SOURCES
  "${SRCROOT}${INPUTOUTPUTDIR}/basicInputOutput.cpp"
)

# Set header files.
set(INPUTOUTPUT_HEADERS
  "${SRCROOT}${INPUTOUTPUTDIR}/basicInputOutput.h"
  "${SRCROOT}${INPUTOUTPUTDIR}/rootPath.h"  
)

# Set unit test files.
set(INPUTOUTPUT_UNIT_TESTS
    "${SRCROOT}${INPUTOUTPUTDIR}/UnitTests/unitTestInputOutput.cpp"
    "${SRCROOT}${INPUTOUTPUTDIR}/UnitTests/unitTestBasicInputOutput.cpp"
    "${SRCROOT}${INPUTOUTPUTDIR}/UnitTests/unitTestRootPath.cpp"
)

# Add static library.
add_library(assist_input_output STATIC ${INPUTOUTPUT_SOURCES} ${INPUTOUTPUT_HEADERS})
setup_library_target(assist_input_output)

# Add unit tests.
add_executable(test_InputOutput ${INPUTOUTPUT_UNIT_TESTS})
setup_unit_test_target(test_InputOutput)
target_link_libraries(test_InputOutput 
                      assist_input_output 
                      ${TUDAT_CORE_LIBRARIES}
                      ${Boost_LIBRARIES})
