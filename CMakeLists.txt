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

add_subdirectory(MyApp)
if(ENABLE_GTEST)
message(STATUS "Started Google Test!")
set(gtest_build_tests OFF)
set(gtest_build_samples OFF)
set(gtest_disable_pthreads ON)
add_subdirectory(googletest)
add_subdirectory(MyTest)
message(STATUS "Finished Google Test!")
endif()
