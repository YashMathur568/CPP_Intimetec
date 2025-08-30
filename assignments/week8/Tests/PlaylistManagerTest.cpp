#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/PlaylistManager.h"
#include <filesystem>

class PlaylistManagerTest : public ::testing::Test
{
protected:
    PlaylistManager *manager;
    std::string testDir;

    void SetUp() override
    {
        manager = new PlaylistManager();
        testDir = "../Playlists";
        std::filesystem::create_directories(testDir);
    }

    void TearDown() override
    {
        delete manager;
        std::filesystem::remove_all(testDir);
    }
};

TEST_F(PlaylistManagerTest, CreatePlaylist_NewName_ReturnsTrue)
{
    bool result = manager->createPlaylist("New Playlist");
    EXPECT_TRUE(result);
}

TEST_F(PlaylistManagerTest, CreatePlaylist_ExistingName_ReturnsFalse)
{
    manager->createPlaylist("Existing Playlist");
    bool result = manager->createPlaylist("Existing Playlist");
    EXPECT_FALSE(result);
}

TEST_F(PlaylistManagerTest, DeletePlaylist_ExistingPlaylist_ReturnsTrue)
{
    manager->createPlaylist("To Delete");
    bool result = manager->deletePlaylist("To Delete");
    EXPECT_TRUE(result);
}

TEST_F(PlaylistManagerTest, GetPlaylist_ExistingPlaylist_ReturnsPlaylist)
{
    manager->createPlaylist("Existing");
    IPlaylist *playlist = manager->getPlaylist("Existing");
    EXPECT_NE(playlist, nullptr);
}