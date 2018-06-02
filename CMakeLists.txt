cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runMyStringTest MyString_test.cpp)
target_link_libraries(runMyStringTest ${GTEST_LIBRARIES} pthread)

add_executable(runMyQueueTest MyQueue_test.cpp)
target_link_libraries(runMyQueueTest ${GTEST_LIBRARIES} pthread)