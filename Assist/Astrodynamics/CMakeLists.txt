 #    Copyright (c) 2010-2014, Delft University of Technology
 #    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 #    All rights reserved.
 #    See http://bit.ly/1jern3m for license details.

# Set source files.
# !!! COMMENTED OUT SINCE THERE ARE NO SOURCE FILES IN THIS DIRECTORY !!!
#set(ASTRODYNAMICS_SOURCES
#)

# Set header files.
set(ASTRODYNAMICS_HEADERS
  "${SRCROOT}${ASTRODYNAMICSDIR}/astrodynamicsBasics.h"
  "${SRCROOT}${ASTRODYNAMICSDIR}/unitConversions.h"
)

# Set unit test files.
set(ASTRODYNAMICS_UNIT_TESTS
  "${SRCROOT}${ASTRODYNAMICSDIR}/UnitTests/unitTestAstrodynamics.cpp"
  "${SRCROOT}${ASTRODYNAMICSDIR}/UnitTests/unitTestAstrodynamicsBasics.cpp"
  "${SRCROOT}${ASTRODYNAMICSDIR}/UnitTests/unitTestUnitConversions.cpp"
)

# Add static library.
# !!! COMMENTED OUT SINCE THERE ARE NO SOURCE FILES IN THIS DIRECTORY !!!
#add_library(assist_astrodynamics STATIC ${ASTRODYNAMICS_SOURCES} ${ASTRODYNAMICS_HEADERS})
#setup_library_target(assist_astrodynamics)

# Add unit tests.
add_executable(test_Astrodynamics ${ASTRODYNAMICS_UNIT_TESTS})
setup_unit_test_target(test_Astrodynamics)
target_link_libraries(test_Astrodynamics 
                      ${Boost_LIBRARIES})
