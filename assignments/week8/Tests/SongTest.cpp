#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Song.h"

class SongTest : public ::testing::Test
{
protected:
    Song *song;

    void SetUp() override
    {
        song = new Song("/path/of/song.ogg", "Test Song");
    }

    void TearDown() override
    {
        delete song;
    }
};

TEST_F(SongTest, GetPath_ReturnsCorrectPath)
{
    EXPECT_EQ(song->getPath(), "/path/of/song.ogg");
}

TEST_F(SongTest, GetName_ReturnsCorrectName)
{
    EXPECT_EQ(song->getName(), "Test Song");
}