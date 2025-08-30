#ifndef MUSICPLAYLISTSYSTEM_H
#define MUSICPLAYLISTSYSTEM_H

#include "IMusicPlaylistSystem.h"

class MusicPlaylistSystem : public IMusicPlaylistSystem
{
private:
    IPlaylistManager *manager;
    IMusicPlayer *player;

public:
    MusicPlaylistSystem(IPlaylistManager *m, IMusicPlayer *p);

    void showMainMenu() override;
    void showPlaylistMenu(IPlaylist *selectedPlaylist) override;
    void displaySongs(const IPlaylist *playlist) override;
};

#endif
