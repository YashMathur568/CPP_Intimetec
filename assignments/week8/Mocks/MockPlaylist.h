#ifndef MOCKPLAYLIST_H
#define MOCKPLAYLIST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../include/IPlaylist.h"

class MockPlaylist : public IPlaylist
{
public:
    MOCK_METHOD(void, addSong, (ISong * song), (override));
    MOCK_METHOD(void, removeSongAt, (int index), (override));
    MOCK_METHOD(void, moveSongUp, (int index), (override));
    MOCK_METHOD(void, moveSongDown, (int index), (override));
    MOCK_METHOD(void, loadFromFile, (const std::string &filename), (override));
    MOCK_METHOD(void, saveToFile, (const std::string &filename), (const, override));
    MOCK_METHOD(const std::vector<ISong *> &, getSongs, (), (const, override));
    MOCK_METHOD(std::string, getName, (), (const, override));
};

#endif