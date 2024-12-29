cmake_minimum_required(VERSION 3.10)

project(LW_3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
    TLS_VERIFY false
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(LW4_lib src/exceptions.cpp src/tools.cpp)



add_executable(LW4 main.cpp)
target_link_libraries(LW4 PRIVATE LW4_lib)

enable_testing()

add_executable(LW4_tests test/test_solver.cpp)
target_link_libraries(LW4_tests PRIVATE LW4_lib gtest gmock gtest_main)

add_test(NAME MyProjectTests COMMAND LW4_tests)