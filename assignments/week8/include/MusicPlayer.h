#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "IMusicPlayer.h"
#include "IAudioPlayer.h"

class MusicPlayer : public IMusicPlayer
{
private:
    IPlaylist *currentPlaylist;
    int currentIndexPlaying;
    bool isPlaying;
    IAudioPlayer *audioPlayer;
    bool ownsAudioPlayer;

public:
    MusicPlayer(IAudioPlayer *audio, bool takeOwnership = true);
    ~MusicPlayer();

    // // Disable copy constructor and assignment to prevent double deletion
    // MusicPlayer(const MusicPlayer &) = delete;
    // MusicPlayer &operator=(const MusicPlayer &) = delete;

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