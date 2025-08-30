#ifndef SFMLAUDIOPLAYER_H
#define SFMLAUDIOPLAYER_H

#include "IAudioPlayer.h"
#include <SFML/Audio.hpp>

class SFMLAudioPlayer : public IAudioPlayer
{
private:
    sf::Music music;

public:
    bool openFromFile(const std::string &filename) override;
    void play() override;
    void pause() override;
    void stop() override;
    AudioStatus getStatus() const override;
};

#endif