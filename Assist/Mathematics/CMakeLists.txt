 #    Copyright (c) 2010-2014, Delft University of Technology
 #    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 #    All rights reserved.
 #    See http://bit.ly/1jern3m for license details.

# Set source files.
set(MATHEMATICS_SOURCES
 "${SRCROOT}${MATHEMATICSDIR}/statistics.cpp"
)

# Set header files.
set(MATHEMATICS_HEADERS
  "${SRCROOT}${MATHEMATICSDIR}/statistics.h"
)

# Set unit test files.
set(MATHEMATICS_UNIT_TESTS
    "${SRCROOT}${MATHEMATICSDIR}/UnitTests/unitTestMathematics.cpp"
    "${SRCROOT}${MATHEMATICSDIR}/UnitTests/unitTestStatistics.cpp"
)

# Add static library.
add_library(assist_mathematics STATIC ${MATHEMATICS_SOURCES} ${MATHEMATICS_HEADERS})
setup_library_target(assist_mathematics)

# Add unit tests.
add_executable(test_Mathematics ${MATHEMATICS_UNIT_TESTS})
setup_unit_test_target(test_Mathematics)
target_link_libraries(test_Mathematics 
                      assist_mathematics 
                      ${Boost_LIBRARIES})
