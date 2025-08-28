#ifndef IMUSICPLAYER_H
#define IMUSICPLAYER_H

#include "IPlaylist.h"

class IMusicPlayer
{
public:
    virtual ~IMusicPlayer() = default;

    virtual void selectPlaylist(IPlaylist *playlist) = 0;
    virtual void playOrPause() = 0;
    virtual void nextSong() = 0;
    virtual void prevSong() = 0;
    virtual ISong *getCurrentSong() const = 0;
    virtual int getCurrentIndex() const = 0;
    virtual bool isCurrentlyPlaying() const = 0;
    virtual void playAtIndex(const std::vector<ISong *> &songs, int index) = 0;
};

#endif
