###
#  @file CMakeLists.txt
#  @brief CMAKE setting for Google test
#  @author ngmrsng
#  @date 2016/07/11
###
 
cmake_minimum_required (VERSION 2.8.0)
project (GoogleTestSample)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF) 

set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_BUILD_TYPE Debug)

# set parameter
option(ENABLE_GTEST "Use gtest." OFF)

# set parameter value
set(ENABLE_GTEST ON)
set(gtest_build_tests ON)
message (STATUS "ENABLE_GTEST=${ENABLE_GTEST}")

add_subdirectory(MyApp)
if(ENABLE_GTEST)
message(STATUS "Started Google Test!")
add_subdirectory(googletest)
add_subdirectory(MyTest)
message(STATUS "Finished Google Test!")
endif()
