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
set(BASICS_SOURCES
  "${SRCROOT}${BASICSDIR}/void.cpp"
)

# Set header files.
set(BASICS_HEADERS
  "${SRCROOT}${BASICSDIR}/basics.h"
  "${SRCROOT}${BASICSDIR}/commonTypedefs.h"
  "${SRCROOT}${BASICSDIR}/comparisonFunctions.h"
  "${SRCROOT}${BASICSDIR}/operatorOverloadFunctions.h"
)

# Add static library.
add_library(assist_basics STATIC ${BASICS_SOURCES} ${BASICS_HEADERS})
setup_library_target(assist_basics "${SRCROOT}${BASICSDIR}")

# Add unit tests.
add_executable(test_Basics "${SRCROOT}${BASICSDIR}/UnitTests/unitTestBasics.cpp")
setup_unit_test_target(test_Basics "${SRCROOT}${BASICSDIR}")
target_link_libraries(test_Basics assist_basics ${Boost_LIBRARIES})

add_executable(test_CommonTypedefs "${SRCROOT}${BASICSDIR}/UnitTests/unitTestCommonTypedefs.cpp")
setup_unit_test_target(test_CommonTypedefs "${SRCROOT}${BASICSDIR}")
target_link_libraries(test_CommonTypedefs assist_basics ${Boost_LIBRARIES})

add_executable(test_ComparisonFunctions "${SRCROOT}${BASICSDIR}/UnitTests/unitTestComparisonFunctions.cpp")
setup_unit_test_target(test_ComparisonFunctions "${SRCROOT}${BASICSDIR}")
target_link_libraries(test_ComparisonFunctions assist_basics ${Boost_LIBRARIES})

add_executable(test_OperatorOverloadFunctions "${SRCROOT}${BASICSDIR}/UnitTests/unitTestOperatorOverloadFunctions.cpp")
setup_unit_test_target(test_OperatorOverloadFunctions "${SRCROOT}${BASICSDIR}")
target_link_libraries(test_OperatorOverloadFunctions assist_basics ${Boost_LIBRARIES})
