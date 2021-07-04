cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(MyApp)

# test target
set(MyApp_include
	include/SampleFunction.h
)

set(MyApp_src
	src/SampleFunction.cpp
)

add_library(MyApp
	src/main.cpp
	${MyApp_include}
	${MyApp_src}
)

include_directories(MyApp
PUBLIC
	include
PRIVATE
	src
)

# TODO
if(MSVC)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
else()
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O -Wall")
endif()