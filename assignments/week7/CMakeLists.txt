cmake_minimum_required(VERSION 3.14)
project(BankingSystemTests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include(GoogleTest)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/interfaces
    ${CMAKE_SOURCE_DIR}/src/mocks
    ${GTEST_INCLUDE_DIRS}
)

set(SOURCES
    src/Transaction.cpp
    src/User.cpp
    src/Account.cpp
    src/AccountHolder.cpp
    src/Admin.cpp
    src/Bank.cpp
    src/InputValidation.cpp
    src/TimeService.cpp
)

set(TEST_SOURCES
    tests/TransactionTest.cpp
    tests/UserTest.cpp
    tests/InputValidationTest.cpp
    tests/AccountTest.cpp
    tests/AccountHolderTest.cpp
    tests/AdminTest.cpp
    tests/BankTest.cpp
    tests/IntegrationTest.cpp
    tests/TestRunner.cpp
)

add_executable(BankingSystemTests 
    ${SOURCES} 
    ${TEST_SOURCES}
)


target_link_libraries(BankingSystemTests 
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
    GTest::gmock_main
    pthread
)

enable_testing()
add_test(NAME BankingSystemTests COMMAND BankingSystemTests)