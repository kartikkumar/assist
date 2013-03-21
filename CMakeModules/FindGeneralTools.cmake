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
 #      12xxxx    B. Tong Minh      File created based on FindEigen3.cmake.
 #      130211    K. Kumar          Updated for General Tools project. 
 #
 #    References
 #      FindEigen3.cmake.
 #
 #    Notes
 #      This script tries to find the General Tools library (part of the suite of applications for
 #      planetary rings). This module supports requiring a minimum version, e.g. you can do version,
 #      e.g. you can do find_package(GeneralTools 3.1.2) to require version 3.1.2 or newer of
 #      Tudat.
 #
 #      Once done, this will define:
 #
 #          GENERAL_TOOLS_FOUND - system has GeneralTools lib with correct version;
 #          GENERAL_TOOLS_INCLUDE_DIR - the GeneralTools include directory.
 #
 #      Original copyright statements (from FindEigen3.cmake:
 #          Copyright (c) 2006, 2007 Montel Laurent, <montel@kde.org>
 #          Copyright (c) 2008, 2009 Gael Guennebaud, <g.gael@free.fr>
 #          Copyright (c) 2009 Benoit Jacob <jacob.benoit.1@gmail.com>
 #
 #      FindEigen3.cmake states that redistribution and use is allowed according to the terms of
 #      the 2-clause BSD license.
 #

macro(_general_tools_check_version)
  file(READ "${GENERAL_TOOLS_INCLUDE_DIR}/GeneralTools/generalToolsVersion.h" _general_tools_header)

  string(REGEX MATCH "define[ \t]+GENERAL_TOOLS_VERSION_MAJOR[ \t]+([0-9]+)" _general_tools_major_version_match "${_general_tools_header}")
  set(GENERAL_TOOLS_MAJOR_VERSION "${CMAKE_MATCH_1}")
  string(REGEX MATCH "define[ \t]+GENERAL_TOOLS_VERSION_MINOR[ \t]+([0-9]+)" _general_tools_minor_version_match "${_general_tools_header}")
  set(GENERAL_TOOLS_MINOR_VERSION "${CMAKE_MATCH_1}")

  set(GENERAL_TOOLS_VERSION ${GENERAL_TOOLS_MAJOR_VERSION}.${GENERAL_TOOLS_MINOR_VERSION})
  if(${GENERAL_TOOLS_VERSION} VERSION_LESS ${GeneralTools_FIND_VERSION})
    set(GENERAL_TOOLS_VERSION_OK FALSE)
  else(${GENERAL_TOOLS_VERSION} VERSION_LESS ${GeneralTools_FIND_VERSION})
    set(GENERAL_TOOLS_VERSION_OK TRUE)
  endif(${GENERAL_TOOLS_VERSION} VERSION_LESS ${GeneralTools_FIND_VERSION})

  if(NOT GENERAL_TOOLS_VERSION_OK)

    message(STATUS "Tudat version ${GENERAL_TOOLS_VERSION} found in ${GENERAL_TOOLS_INCLUDE_DIR}, "
                   "but at least version ${GeneralTools_FIND_VERSION} is required")
  endif(NOT GENERAL_TOOLS_VERSION_OK)

  set(GENERAL_TOOLS_LIBRARIES "general_tools")
  link_directories(${GENERAL_TOOLS_LIBRARIES_DIR})
endmacro(_general_tools_check_version)

if (GENERAL_TOOLS_INCLUDE_DIR)

  # in cache already
  _general_tools_check_version()
  set(GENERAL_TOOLS_FOUND ${GENERAL_TOOLS_VERSION_OK})

else (GENERAL_TOOLS_INCLUDE_DIR)

  find_path(GENERAL_TOOLS_BASE_PATH NAMES generalToolsVersion.h
      PATHS
      ${PROJECT_SOURCE_DIR}/../../generalTools
      PATH_SUFFIXES GeneralTools 
    )
  set(GENERAL_TOOLS_INCLUDE_DIR ${GENERAL_TOOLS_BASE_PATH}/../)
  set(GENERAL_TOOLS_LIBRARIES_DIR ${GENERAL_TOOLS_BASE_PATH}/../lib)

  if(GENERAL_TOOLS_INCLUDE_DIR)
    _general_tools_check_version()
  endif(GENERAL_TOOLS_INCLUDE_DIR)

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(GeneralTools DEFAULT_MSG GENERAL_TOOLS_INCLUDE_DIR GENERAL_TOOLS_VERSION_OK)

  mark_as_advanced(GENERAL_TOOLS_INCLUDE_DIR)

endif(GENERAL_TOOLS_INCLUDE_DIR)
