 #    Copyright (c) 2010-2014, Delft University of Technology
 #    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 #    All rights reserved.
 #    See http://bit.ly/1jern3m for license details.

# Set source files.
# !!! COMMENTED OUT SINCE THERE ARE NO SOURCE FILES IN THIS DIRECTORY !!!
#set(BASICS_SOURCES
#)

# Set header files.
set(BASICS_HEADERS
  "${SRCROOT}${BASICSDIR}/commonTypedefs.h"
  "${SRCROOT}${BASICSDIR}/comparisonFunctions.h"
  "${SRCROOT}${BASICSDIR}/operatorOverloadFunctions.h"
)

# Set unit test files.
set(BASICS_UNIT_TESTS
  "${SRCROOT}${BASICSDIR}/UnitTests/unitTestBasics.cpp"
  "${SRCROOT}${BASICSDIR}/UnitTests/unitTestCommonTypedefs.cpp"
  "${SRCROOT}${BASICSDIR}/UnitTests/unitTestComparisonFunctions.cpp"
  "${SRCROOT}${BASICSDIR}/UnitTests/unitTestOperatorOverloadFunctions.cpp"
)

# Add static library.
# !!! COMMENTED OUT SINCE THERE ARE NO SOURCE FILES IN THIS DIRECTORY !!!
#add_library(assist_basics STATIC ${BASICS_SOURCES} ${BASICS_HEADERS})
#setup_library_target(assist_basics)

# Add unit tests.
add_executable(test_Basics ${BASICS_UNIT_TESTS})
setup_unit_test_target(test_Basics)
target_link_libraries(test_Basics 
                      ${Boost_LIBRARIES})
