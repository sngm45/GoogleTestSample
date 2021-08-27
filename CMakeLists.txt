###
#  @file CMakeLists.txt
#  @brief CMAKE setting for Google test
#  @author sngm45
#  @date 2021/07/01
###

cmake_minimum_required (VERSION 3.13 FATAL_ERROR)

SET (CMAKE_C_COMPILER_WORKS OFF)
SET (CMAKE_CXX_COMPILER_WORKS ON)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF) 

set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_BUILD_TYPE "Debug")

project(GoogleTestSample CXX)

# set parameter
option(ENABLE_GTEST "Use gtest." OFF)

# set parameter value
set(ENABLE_GTEST ON)
message (STATUS "ENABLE_GTEST=${ENABLE_GTEST}")

# fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)
set(currentHelpString CACHE "" PROPERTY HELPSTRING)
set(BUILD_GMOCK CACHE BOOL OFF ${currentHelpString})
set(INSTALL_GTEST CACHE BOOL OFF ${currentHelpString})

if(WIN32)
  set(gtest_force_shared_crt ON CACHE BOOL ${currentHelpString})
endif()
FetchContent_MakeAvailable(googletest)

add_subdirectory(MyApp)
if(ENABLE_GTEST)
message(STATUS "Started Google Test!")
set(gtest_build_tests OFF)
set(gtest_build_samples OFF)
set(gtest_disable_pthreads ON)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()
add_subdirectory(MyTest)
message(STATUS "Finished Google Test!")
endif()
