cmake_minimum_required(VERSION 3.14)
project(BankingSystemTests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
find_package(SFML 2.5 COMPONENTS audio REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/Mocks
)

set(SOURCES
    src/InputValidation.cpp
    src/MusicPlayer.cpp
    src/Playlist.cpp
    src/PlaylistManager.cpp
    src/MusicPlaylistSystem.cpp
    src/Song.cpp
    src/SFMLAudioPlayer.cpp
)

set(TEST_SOURCES
    Tests/MusicPlayerTest.cpp
    Tests/PlaylistTest.cpp
    Tests/PlaylistManagerTest.cpp
    Tests/SongTest.cpp
)

add_executable(MusicPlayerTests 
    ${SOURCES} 
    ${TEST_SOURCES}
)

add_executable(MusicPlayer 
    ${SOURCES}
    main.cpp
)

target_link_libraries(MusicPlayer sfml-audio sfml-system)

target_link_libraries(MusicPlayerTests 
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
    GTest::gmock_main
    sfml-audio
    sfml-system
)