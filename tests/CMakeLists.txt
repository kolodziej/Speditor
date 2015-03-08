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

set(CMAKE_CXX_FLAGS "-std=c++11 -g")
set(LIBRARIES gtest gtest_main Speditor)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

add_executable(logger logger.cpp)
target_link_libraries(logger "${LIBRARIES}")

add_executable(map map.cpp)
target_link_libraries(map "${LIBRARIES}")

add_executable(route route.cpp)
target_link_libraries(route "${LIBRARIES}")

add_executable(traffic_policy traffic_policy.cpp)
target_link_libraries(traffic_policy "${LIBRARIES}")

add_executable(timepoint timepoint.cpp)
target_link_libraries(timepoint "${LIBRARIES}")
