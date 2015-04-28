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

set(CMAKE_CXX_FLAGS "-std=c++11 -g -DDEBUG -DOFF_LOG_DETAIL")
set(LIBRARIES gtest gtest_main Speditor)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

set(TESTS
  "logger"
  "map"
  "route"
  "schedule"
  "timepoint"
  "traffic_policy"
)

foreach(TEST ${TESTS})
  set(BIN "${TEST}.gtest")
  set(SRC "${TEST}.cpp")
  add_executable("${BIN}" "${SRC}")
  target_link_libraries("${BIN}" "${LIBRARIES}")
endforeach(TEST)

add_executable(clock clock.cpp)
target_link_libraries(clock Speditor pthread)
