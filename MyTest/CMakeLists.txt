cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(MyTest)

####################################################
# tests
set(MyTest_src
	src/main.cpp
)

set(MyTest_test
	test/SampleTestCase.cpp
)

# configuration
set(MyTest_CONFIGURATION_IN ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h.in)
set(MyTest_CONFIGURATION ${CMAKE_CURRENT_BINARY_DIR}/include/config.h)
configure_file( ${MyTest_CONFIGURATION_IN} ${MyTest_CONFIGURATION} )

find_package(Threads REQUIRED)

enable_testing()

add_executable(MyTest
	${MyTest_src}
	${MyTest_test}
	${MyTest_CONFIGURATION}
)

####################################################
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/../MyApp/include
	${CMAKE_CURRENT_BINARY_DIR}/include
)

target_link_libraries(MyTest PRIVATE MyApp)

####################################################
# link google test
#if(DEFINED ENABLE_GTEST)
  if (MSVC)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /NODEFAULTLIB:MSVCRT:lib")
  else()
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS}  -Wall -O2 -Wformat")
  endif()
	set(GTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../googletest)
	set(GTEST_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/../googletest)
	include_directories(${GTEST_DIR} ${GTEST_BUILD_DIR})

	# include
	set(GTEST_INCLUDE_DIR ${GTEST_DIR}/include)
	include_directories(${GTEST_INCLUDE_DIR})

	# library
  if (MSVC)
	set(GTEST_LIB ${CMAKE_CURRENT_BINARY_DIR}/../googletest/gtest.dir/${CMAKE_CFG_INTDIR}/gtest-all.obj)
	set(GTEST_MAIN ${CMAKE_CURRENT_BINARY_DIR}/../googletest/${CMAKE_CFG_INTDIR}/gtest_main)
  else()
	set(GTEST_LIB ${CMAKE_CURRENT_BINARY_DIR}/../googletest/libgtest.a)
	set(GTEST_MAIN ${CMAKE_CURRENT_BINARY_DIR}/../googletest/libgtest_main.a)
  endif()
#	target_link_libraries(MyTest PRIVATE ${GTEST_LIB} ${GTEST_MAIN} Threads::Threads)
        target_link_libraries(MyTest PRIVATE gtest_main Threads::Threads)
#endif()

  if (MSVC)
	set_target_properties(MyTest PROPERTIES LINK_FLAGS /SUBSYSTEM:CONSOLE)
  endif()

add_test(NAME MyTest 
	COMMAND MyTest
)

include(GoogleTest)
gtest_discover_tests(MyTest)
