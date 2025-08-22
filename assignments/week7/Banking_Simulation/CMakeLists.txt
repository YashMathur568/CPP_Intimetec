cmake_minimum_required(VERSION 3.14)
project(BankingSystemTests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include(GoogleTest)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/interfaces
    ${CMAKE_SOURCE_DIR}/include/mocks
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
)

add_executable(BankingSystemTests 
    ${SOURCES} 
    ${TEST_SOURCES}
)

add_executable(BankingApp 
    ${SOURCES}
    main.cpp
)

target_link_libraries(BankingSystemTests 
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
    GTest::gmock_main
    pthread
)

target_link_libraries(BankingApp 
    pthread
)

enable_testing()
add_test(NAME BankingSystemTests COMMAND BankingSystemTests)