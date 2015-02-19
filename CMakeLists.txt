cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Speditor)

include_directories(
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/googletest"
	"${PROJECT_SOURCE_DIR}"
)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -static -lm")

set(SD "${PROJECT_SOURCE_DIR}")

set(SOURCES
 "${SD}/src/map.cpp"
 "${SD}/src/city.cpp"
 "${SD}/src/node.cpp"
 "${SD}/src/road.cpp"
 "${SD}/src/route.cpp"
 "${SD}/src/clock.cpp"
 "${SD}/src/timepoint.cpp"
)

set(HEADERS
	"${SD}/include/map.hpp"
	"${SD}/include/city.hpp"
	"${SD}/include/node.hpp"
	"${SD}/include/node_type.hpp"
	"${SD}/include/road.hpp"
	"${SD}/include/route.hpp"
	"${SD}/include/clock.hpp"
	"${SD}/include/timepoint.hpp"
)

add_library(Speditor STATIC ${HEADERS} ${SOURCES})

if(MAKE_TESTS)
	add_subdirectory(googletest)
	add_subdirectory(tests)
endif(MAKE_TESTS)
