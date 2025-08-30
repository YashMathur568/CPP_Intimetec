#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Playlist.h"
#include "../include/Song.h"
#include "../Mocks/MockSong.h"
#include <filesystem>

class PlaylistTest : public ::testing::Test
{
protected:
    Playlist *playlist;
    MockSong *mockSong1;
    MockSong *mockSong2;
    std::string testDir;
    std::string testFile;

    void SetUp() override
    {
        playlist = new Playlist("Test Playlist", false);
        mockSong1 = new MockSong();
        mockSong2 = new MockSong();

        testDir = "./test_playlists";
        testFile = testDir + "/test.json";
        std::filesystem::create_directories(testDir);

        ON_CALL(*mockSong1, getName()).WillByDefault(testing::Return("Song 1"));
        ON_CALL(*mockSong1, getPath()).WillByDefault(testing::Return("/path/song1.ogg"));
        ON_CALL(*mockSong2, getName()).WillByDefault(testing::Return("Song 2"));
        ON_CALL(*mockSong2, getPath()).WillByDefault(testing::Return("/path/song2.ogg"));

        EXPECT_CALL(*mockSong1, getName()).Times(testing::AnyNumber());
        EXPECT_CALL(*mockSong1, getPath()).Times(testing::AnyNumber());
        EXPECT_CALL(*mockSong2, getName()).Times(testing::AnyNumber());
        EXPECT_CALL(*mockSong2, getPath()).Times(testing::AnyNumber());
    }

    void TearDown() override
    {
        delete playlist;
        delete mockSong1;
        delete mockSong2;
        std::filesystem::remove_all(testDir);
    }
};

TEST_F(PlaylistTest, AddSong_IncreasesSize)
{
    playlist->addSong(mockSong1);
    EXPECT_EQ(playlist->getSongs().size(), 1);
}

TEST_F(PlaylistTest, RemoveSongAt_ValidIndex_RemovesSong)
{
    playlist->addSong(mockSong1);
    playlist->addSong(mockSong2);

    playlist->removeSongAt(0);

    EXPECT_EQ(playlist->getSongs().size(), 1);
    EXPECT_EQ(playlist->getSongs()[0]->getName(), "Song 2");
}