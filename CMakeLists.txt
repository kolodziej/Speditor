cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Speditor)

include_directories(
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}"
)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG -DLOG_INFO -DLOG_ERROR -DLOG_WARNING -DLOG_CRITICAL")
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
	"${SD}/src/tools/logger.cpp"
	"${SD}/src/routing_policy/shortest.cpp"
	"${SD}/src/routing_policy/fastest.cpp"
	"${SD}/src/routing_policy/economical.cpp"
	"${SD}/src/traffic_policy/chain.cpp"
	"${SD}/src/traffic_policy/sinus.cpp"
	"${SD}/src/tasks/task.cpp"
	"${SD}/src/tasks/queue.cpp"
)

set(HEADERS
	"${SD}/include/map.hpp"
	"${SD}/include/city.hpp"
	"${SD}/include/crossroads.hpp"
	"${SD}/include/node.hpp"
	"${SD}/include/node_type.hpp"
	"${SD}/include/road.hpp"
	"${SD}/include/route.hpp"
	"${SD}/include/clock.hpp"
	"${SD}/include/timepoint.hpp"
	"${SD}/include/tools/logger.hpp"
	"${SD}/include/tools/log_type.hpp"
	"${SD}/impl/tools/logger.hpp"
	"${SD}/include/routing_policy/abstract.hpp"
	"${SD}/include/routing_policy/policies.hpp"
	"${SD}/include/routing_policy/shortest.hpp"
	"${SD}/include/routing_policy/fastest.hpp"
	"${SD}/include/routing_policy/economical.hpp"
	"${SD}/include/traffic_policy/policy.hpp"
	"${SD}/include/traffic_policy/chain.hpp"
	"${SD}/include/traffic_policy/sinus.hpp"
	"${SD}/include/tasks/task.hpp"
	"${SD}/include/tasks/queue.hpp"
)

add_library(Speditor STATIC ${HEADERS} ${SOURCES})

if(MAKE_TESTS)
	add_subdirectory(googletest)
	add_subdirectory(tests)
endif(MAKE_TESTS)
