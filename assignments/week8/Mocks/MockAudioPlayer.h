#ifndef MOCKAUDIOPLAYER_H
#define MOCKAUDIOPLAYER_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../include/IAudioPlayer.h"

class MockAudioPlayer : public IAudioPlayer
{
public:
    MOCK_METHOD(bool, openFromFile, (const std::string &filename), (override));
    MOCK_METHOD(void, play, (), (override));
    MOCK_METHOD(void, pause, (), (override));
    MOCK_METHOD(void, stop, (), (override));
    MOCK_METHOD(AudioStatus, getStatus, (), (const, override));
};

#endif