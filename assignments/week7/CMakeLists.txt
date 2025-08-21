
cmake_minimum_required(VERSION 3.10)


project(MyProject)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(my_project
    src/Account.cpp
    src/AccountHolder.cpp
    src/Admin.cpp
    src/Bank.cpp
    src/InputValidation.cpp
    src/Transaction.cpp
    src/User.cpp
    main.cpp
)


include_directories(${PROJECT_SOURCE_DIR}/include)

enable_testing()


add_subdirectory(googletest)


add_executable(test_example
    tests/AdminTest.cpp
    src/Account.cpp
    src/Admin.cpp
    src/Bank.cpp
    src/Transaction.cpp
    src/InputValidation.cpp
    src/User.cpp
)

target_link_libraries(test_example gtest gtest_main gmock)
