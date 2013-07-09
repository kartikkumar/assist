 #    
 #    Copyright (c) 2010-2013, Delft University of Technology
 #    All rights reserved.
 #    See COPYING for license details.
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
