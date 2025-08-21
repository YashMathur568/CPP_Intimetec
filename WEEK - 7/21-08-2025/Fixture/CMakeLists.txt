# Minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Setting the project name
project(MyProject)

# Setting the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the googletest subdirectory (make sure googletest is in the project root)
add_subdirectory(googletest)

# Include directories for your own headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Adding the path to the source files for main executable
add_executable(my_project
    src/Account.cpp
)

# Enable testing
enable_testing()

# Adding test executable with all required source files
add_executable(test_example
    test/AccountTest.cpp
    src/Account.cpp
)

# Link GoogleTest to the main project executable (if needed)
target_link_libraries(my_project gtest gtest_main)
# Link GoogleTest and GoogleMock to the test executable
target_link_libraries(test_example gtest gmock gtest_main )