# Minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Setting the project name
project(MyProject)

# Setting the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adding the path to the source files
add_executable(my_project
    src/sayHello.cpp
    src/UserDefinedType.cpp
    src/stringcheck.cpp
)

enable_testing()

# Adding GoogleTest subdirectory
add_subdirectory(googletest)

# Adding test executable
add_executable(test_example
    test/testHello.cpp
    test/UserDefinedTypeTest.cpp
    test/stringcheckTest.cpp
    )

# Linking GoogleTest to the test executable
target_link_libraries(test_example gtest gtest_main)

# Linking GoogleTest with the main project executable
target_link_libraries(my_project gtest gtest_main)
