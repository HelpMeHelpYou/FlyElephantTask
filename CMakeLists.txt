cmake_minimum_required(VERSION 2.8)

project(FlyElephantTask)

set (CMAKE_CXX_STANDARD 11)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

set(SOURCE "argparser.cpp" "resource.cpp" "flytoelephantalgorythm.cpp")
set (TESTS_SOURCE "test.cpp" "testargparser.cpp" "testresource.cpp" "testflytoelephantalgorithm.cpp")
set (MAIN_SOURCE "main.cpp")

add_executable( runUnitTests ${SOURCE} ${TESTS_SOURCE} )
target_link_libraries(runUnitTests gtest gtest_main)
target_link_libraries(runUnitTests Threads::Threads)

add_test( runUnitTests runUnitTests )

add_executable(${PROJECT_NAME} ${MAIN_SOURCE} ${SOURCE})

