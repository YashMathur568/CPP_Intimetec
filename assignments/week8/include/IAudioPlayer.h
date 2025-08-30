#ifndef IAUDIOPLAYER_H
#define IAUDIOPLAYER_H

#include <string>

enum class AudioStatus
{
    Stopped,
    Playing,
    Paused
};

class IAudioPlayer
{
public:
    virtual ~IAudioPlayer() = default;

    virtual bool openFromFile(const std::string &filename) = 0;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual AudioStatus getStatus() const = 0;
};

#endif