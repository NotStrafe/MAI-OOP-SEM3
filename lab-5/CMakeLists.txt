cmake_minimum_required(VERSION 3.10)
project(oop_lab5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main_lab5 main.cpp src/ListMemoryResource.cpp)

target_include_directories(main_lab5 PRIVATE include)


enable_testing()

add_executable(tests_lab5 tests/tests.cpp src/ListMemoryResource.cpp)

target_include_directories(tests_lab5 PRIVATE include)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

target_link_libraries(tests_lab5 gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests_lab5)