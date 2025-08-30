#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Mocks/MockAudioPlayer.h"
#include "../Mocks/MockPlaylist.h"
#include "../Mocks/MockSong.h"
#include "../include/MusicPlayer.h"

class MusicPlayerTest : public ::testing::Test
{
protected:
    MusicPlayer *player;
    MockAudioPlayer *mockAudio;
    MockPlaylist *mockPlaylist;
    MockSong *mockSong1;
    MockSong *mockSong2;
    std::vector<ISong *> testSongs;

    void SetUp() override
    {
        mockAudio = new MockAudioPlayer();
        player = new MusicPlayer(mockAudio, false);

        mockPlaylist = new MockPlaylist();
        mockSong1 = new MockSong();
        mockSong2 = new MockSong();
        testSongs = {mockSong1, mockSong2};

        ON_CALL(*mockSong1, getName()).WillByDefault(testing::Return("Song 1"));
        ON_CALL(*mockSong1, getPath()).WillByDefault(testing::Return("../audio/song1.ogg"));
        ON_CALL(*mockSong2, getName()).WillByDefault(testing::Return("Song 2"));
        ON_CALL(*mockSong2, getPath()).WillByDefault(testing::Return("../audio/song2.ogg"));
        ON_CALL(*mockPlaylist, getSongs()).WillByDefault(testing::ReturnRef(testSongs));

        EXPECT_CALL(*mockSong1, getName()).Times(testing::AnyNumber());
        EXPECT_CALL(*mockSong1, getPath()).Times(testing::AnyNumber());
        EXPECT_CALL(*mockSong2, getName()).Times(testing::AnyNumber());
        EXPECT_CALL(*mockSong2, getPath()).Times(testing::AnyNumber());
        EXPECT_CALL(*mockPlaylist, getSongs()).Times(testing::AnyNumber());
    }

    void TearDown() override
    {
        delete player;
        delete mockAudio;
        delete mockPlaylist;
        delete mockSong1;
        delete mockSong2;
    }
};

TEST_F(MusicPlayerTest, Constructor_InitializesCorrectState)
{
    EXPECT_EQ(player->getCurrentSong(), nullptr);
    EXPECT_EQ(player->getCurrentIndex(), -1);
    EXPECT_FALSE(player->isCurrentlyPlaying());
}

TEST_F(MusicPlayerTest, PlayAtIndex_ValidIndex_PlaysCorrectSong)
{
    EXPECT_CALL(*mockSong1, getPath())
        .WillOnce(testing::Return("../audio/song1.ogg"));
    EXPECT_CALL(*mockSong1, getName())
        .WillOnce(testing::Return("Song 1"));
    EXPECT_CALL(*mockAudio, openFromFile("../audio/song1.ogg"))
        .WillOnce(testing::Return(true));
    EXPECT_CALL(*mockAudio, play());

    player->playAtIndex(testSongs, 0);

    EXPECT_EQ(player->getCurrentIndex(), 0);
    EXPECT_TRUE(player->isCurrentlyPlaying());
}

TEST_F(MusicPlayerTest, PlayAtIndex_FileOpenFails_HandlesError)
{
    EXPECT_CALL(*mockSong1, getPath())
        .WillOnce(testing::Return("../audio/nonexistent.ogg"));
    EXPECT_CALL(*mockAudio, openFromFile("../audio/nonexistent.ogg"))
        .WillOnce(testing::Return(false));
    EXPECT_CALL(*mockAudio, play()).Times(0);

    player->playAtIndex(testSongs, 0);

    EXPECT_EQ(player->getCurrentIndex(), -1);
    EXPECT_FALSE(player->isCurrentlyPlaying());
}

TEST_F(MusicPlayerTest, GetCurrentSong_WithValidIndex_ReturnsCorrectSong)
{
    player->selectPlaylist(mockPlaylist);

    EXPECT_CALL(*mockSong1, getPath()).WillOnce(testing::Return("../audio/song1.ogg"));
    EXPECT_CALL(*mockSong1, getName()).WillOnce(testing::Return("Song 1"));
    EXPECT_CALL(*mockAudio, openFromFile("../audio/song1.ogg"))
        .WillOnce(testing::Return(true));
    EXPECT_CALL(*mockAudio, play());

    player->playAtIndex(testSongs, 0);

    ISong *currentSong = player->getCurrentSong();
    EXPECT_EQ(currentSong, mockSong1);
}

TEST_F(MusicPlayerTest, PlayOrPause_WhenPlaying_PausesMusic)
{
    EXPECT_CALL(*mockAudio, getStatus())
        .WillOnce(testing::Return(AudioStatus::Playing));
    EXPECT_CALL(*mockAudio, pause());

    player->playOrPause();

    EXPECT_FALSE(player->isCurrentlyPlaying());
}

TEST_F(MusicPlayerTest, PlayOrPause_WhenPaused_ResumesMusic)
{
    EXPECT_CALL(*mockAudio, getStatus())
        .WillOnce(testing::Return(AudioStatus::Paused));
    EXPECT_CALL(*mockAudio, play());

    player->playOrPause();

    EXPECT_TRUE(player->isCurrentlyPlaying());
}

TEST_F(MusicPlayerTest, NextSong_ValidTransition_PlaysNextSong)
{
    player->selectPlaylist(mockPlaylist);

    EXPECT_CALL(*mockSong1, getPath()).WillOnce(testing::Return("../audio/song1.ogg"));
    EXPECT_CALL(*mockSong1, getName()).WillOnce(testing::Return("Song 1"));
    EXPECT_CALL(*mockAudio, openFromFile("../audio/song1.ogg"))
        .WillOnce(testing::Return(true));
    EXPECT_CALL(*mockAudio, play());
    player->playAtIndex(testSongs, 0);

    EXPECT_CALL(*mockSong2, getPath()).WillOnce(testing::Return("../audio/song2.ogg"));
    EXPECT_CALL(*mockSong2, getName()).WillOnce(testing::Return("Song 2"));
    EXPECT_CALL(*mockAudio, openFromFile("../audio/song2.ogg"))
        .WillOnce(testing::Return(true));
    EXPECT_CALL(*mockAudio, play());
    player->nextSong();

    EXPECT_EQ(player->getCurrentIndex(), 1);
    EXPECT_TRUE(player->isCurrentlyPlaying());
}

TEST_F(MusicPlayerTest, PreviousSong_ValidTransition_PlaysPreviousSong)
{
    player->selectPlaylist(mockPlaylist);

    EXPECT_CALL(*mockSong2, getPath()).WillOnce(testing::Return("../audio/song2.ogg"));
    EXPECT_CALL(*mockSong2, getName()).WillOnce(testing::Return("Song 2"));
    EXPECT_CALL(*mockAudio, openFromFile("../audio/song2.ogg"))
        .WillOnce(testing::Return(true));
    EXPECT_CALL(*mockAudio, play());
    player->playAtIndex(testSongs, 1);

    EXPECT_CALL(*mockSong1, getPath()).WillOnce(testing::Return("../audio/song1.ogg"));
    EXPECT_CALL(*mockSong1, getName()).WillOnce(testing::Return("Song 1"));
    EXPECT_CALL(*mockAudio, openFromFile("../audio/song1.ogg"))
        .WillOnce(testing::Return(true));
    EXPECT_CALL(*mockAudio, play());
    player->prevSong();

    EXPECT_EQ(player->getCurrentIndex(), 0);
    EXPECT_TRUE(player->isCurrentlyPlaying());
}
