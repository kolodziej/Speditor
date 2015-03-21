cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Speditor)

include_directories(
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}"
)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g -DDEBUG -DLOG_DETAIL -DLOG_DEBUG -DLOG_ERROR -DLOG_WARNING -DLOG_CRITICAL")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -static -lm")

set(SD "${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS {include,impl}/*.hpp)

add_library(Speditor STATIC ${HEADERS} ${SOURCES})

if(MAKE_TESTS)
	add_subdirectory(googletest)
	add_subdirectory(tests)
endif(MAKE_TESTS)
