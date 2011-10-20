# Install script for directory: /Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/build/libsystemcpp.dylib")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsystemcpp.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsystemcpp.dylib")
    EXECUTE_PROCESS(COMMAND "/usr/bin/install_name_tool"
      -id "libsystemcpp.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsystemcpp.dylib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsystemcpp.dylib")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/System" TYPE FILE FILES
    "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/../Include/System/AtkinSieve.h"
    "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/../Include/System/EratostheneSieve.h"
    "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/../Include/System/Logger.h"
    "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/../Include/System/Mutex.h"
    "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/../Include/System/Prime.h"
    "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/../Include/System/PrimeSieve.h"
    "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/../Include/System/Random.h"
    "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/../Include/System/Semaphore.h"
    "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/../Include/System/Thread.h"
    "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/../Include/System/Time.h"
    "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/../Include/System/Types.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/Users/benoitdaccache/Documents/Programation/C++/CPPWrappers/System/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
