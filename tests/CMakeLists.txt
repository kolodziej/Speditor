cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

link_directories(
	"../lib/"
	"../googletest/"
)

include_directories(
	"../include/"
	"../googletest/include/"
	"../"
)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(LIBRARIES gtest gtest_main Speditor)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

add_executable(logger logger.cpp)
target_link_libraries(logger "${LIBRARIES}")