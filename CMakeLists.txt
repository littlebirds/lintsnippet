cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE Debug)

# Locate GTEST
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTest test.cpp)
target_link_libraries(runTest ${GTEST_LIBRARIES} pthread)