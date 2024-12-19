cmake_minimum_required(VERSION 3.10)
project(lab3)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Additional compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Add library
add_library(${CMAKE_PROJECT_NAME}_lib
    src/hexagon.cpp
    src/pentagon.cpp
    src/point.cpp
    src/rhomb.cpp
    src/Vector.cpp
)

# Add executable for the main program
add_executable(main main.cpp)
target_link_libraries(main PRIVATE ${CMAKE_PROJECT_NAME}_lib)

# Include FetchContent for GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add executable for unit tests
add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE ${CMAKE_PROJECT_NAME}_lib gtest_main)

# Add test target
add_test(NAME Lab3Tests COMMAND tests)
