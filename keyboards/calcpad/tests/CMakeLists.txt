cmake_minimum_required(VERSION 3.0)

project(bcd)
enable_testing()
add_subdirectory(../../../lib/googletest googletest)
include_directories(../../../lib/googletest)
add_executable(bcd_tests ../bcd.c bcd_tests.cpp)
target_link_libraries(bcd_tests gtest_main)
