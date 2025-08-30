#ifndef MOCKSONG_H
#define MOCKSONG_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../include/ISong.h"

class MockSong : public ISong
{
public:
    MOCK_METHOD(std::string, getPath, (), (const, override));
    MOCK_METHOD(std::string, getName, (), (const, override));
};

#endif