#include "SFMLAudioPlayer.h"

bool SFMLAudioPlayer::openFromFile(const std::string &filename)
{
    return music.openFromFile(filename);
}

void SFMLAudioPlayer::play()
{
    music.play();
}

void SFMLAudioPlayer::pause()
{
    music.pause();
}

void SFMLAudioPlayer::stop()
{
    music.stop();
}

AudioStatus SFMLAudioPlayer::getStatus() const
{
    switch (music.getStatus())
    {
    case sf::Music::Playing:
        return AudioStatus::Playing;
    case sf::Music::Paused:
        return AudioStatus::Paused;
    case sf::Music::Stopped:
    default:
        return AudioStatus::Stopped;
    }
}
