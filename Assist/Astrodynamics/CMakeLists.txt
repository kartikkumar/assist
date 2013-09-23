 #    
 #    Copyright (c) 2010-2013, Delft University of Technology
 #    All rights reserved.
 #    See COPYING for license details.
 #
 #    Changelog
 #      YYMMDD    Author            Comment
 #      110820    S.M. Persson      File created.
 #      130211    K. Kumar          Adapted file to work with GeneralTools/Astrodynamics.
 #      130320    K. Kumar          Updated static library name to assist*.
 #
 #    References
 #
 #    Notes
 #

# Set source files.
set(ASTRODYNAMICS_SOURCES
  "${SRCROOT}${ASTRODYNAMICSDIR}/void.cpp"
)

# Set header files.
set(ASTRODYNAMICS_HEADERS
  "${SRCROOT}${ASTRODYNAMICSDIR}/astrodynamicsBasics.h"
  "${SRCROOT}${ASTRODYNAMICSDIR}/body.h"
  "${SRCROOT}${ASTRODYNAMICSDIR}/dataUpdater.h"
  "${SRCROOT}${ASTRODYNAMICSDIR}/unitConversions.h"
)

# Add static library.
add_library(assist_astrodynamics STATIC ${ASTRODYNAMICS_SOURCES} ${ASTRODYNAMICS_HEADERS})
setup_library_target(assist_astrodynamics "${SRCROOT}${ASTRODYNAMICSDIR}")

# Add unit tests.
add_executable(test_AstrodynamicsBasics 
               "${SRCROOT}${ASTRODYNAMICSDIR}/UnitTests/unitTestAstrodynamicsBasics.cpp")
setup_unit_test_target(test_AstrodynamicsBasics "${SRCROOT}${ASTRODYNAMICSDIR}")
target_link_libraries(test_AstrodynamicsBasics assist_astrodynamics ${Boost_LIBRARIES})

add_executable(test_Body "${SRCROOT}${ASTRODYNAMICSDIR}/UnitTests/unitTestBody.cpp")
setup_unit_test_target(test_Body "${SRCROOT}${ASTRODYNAMICSDIR}")
target_link_libraries(test_Body assist_astrodynamics assist_basics ${Boost_LIBRARIES})

add_executable(test_DataUpdater "${SRCROOT}${ASTRODYNAMICSDIR}/UnitTests/unitTestDataUpdater.cpp")
setup_unit_test_target(test_DataUpdater "${SRCROOT}${ASTRODYNAMICSDIR}")
target_link_libraries(test_DataUpdater assist_astrodynamics assist_basics ${Boost_LIBRARIES})

add_executable(test_UnitConversions 
               "${SRCROOT}${ASTRODYNAMICSDIR}/UnitTests/unitTestUnitConversions.cpp")
setup_unit_test_target(test_UnitConversions "${SRCROOT}${ASTRODYNAMICSDIR}")
target_link_libraries(test_UnitConversions assist_astrodynamics ${Boost_LIBRARIES})