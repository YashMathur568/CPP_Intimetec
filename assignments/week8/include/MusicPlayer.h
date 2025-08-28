#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "IMusicPlayer.h"
#include <SFML/Audio.hpp>

class MusicPlayer : public IMusicPlayer
{
private:
    IPlaylist *currentPlaylist;
    int currentIndex;
    bool isPlaying;
    sf::Music sfMusic;

public:
    MusicPlayer();

    void selectPlaylist(IPlaylist *playlist) override;
    void playOrPause() override;
    void nextSong() override;
    void prevSong() override;
    ISong *getCurrentSong() const override;
    int getCurrentIndex() const override;
    bool isCurrentlyPlaying() const override;
    void playAtIndex(const std::vector<ISong *> &songs, int index) override;
};

#endif
