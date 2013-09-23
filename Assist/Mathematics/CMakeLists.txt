 #    
 #    Copyright (c) 2010-2013, Delft University of Technology
 #    All rights reserved.
 #    See COPYING for license details.
 #
 #    Changelog
 #      YYMMDD    Author            Comment
 #      110820    S.M. Persson      File created.
 #      130923    K. Kumar          Adapted file for Assist/Mathematics.
 #
 #    References
 #
 #    Notes
 #

# Set source files.
set(MATHEMATICS_SOURCES
 "${SRCROOT}${MATHEMATICSDIR}/statistics.cpp"
)

# Set header files.
set(MATHEMATICS_HEADERS
  "${SRCROOT}${MATHEMATICSDIR}/statistics.h"
)

# Add static library.
add_library(assist_mathematics STATIC ${MATHEMATICS_SOURCES} ${MATHEMATICS_HEADERS})
setup_library_target(assist_mathematics "${SRCROOT}${MATHEMATICSDIR}")

# Add unit tests.
add_executable(test_Statistics "${SRCROOT}${MATHEMATICSDIR}/UnitTests/unitTestStatistics.cpp")
setup_unit_test_target(test_Statistics "${SRCROOT}${MATHEMATICSDIR}")
target_link_libraries(test_Statistics 
                      assist_mathematics 
                      ${Boost_LIBRARIES})