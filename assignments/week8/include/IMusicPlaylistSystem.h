#ifndef IMUSICPLAYLISTSYSTEM_H
#define IMUSICPLAYLISTSYSTEM_H

#include "IPlaylistManager.h"
#include "IMusicPlayer.h"
#include "Playlist.h"

class IMusicPlaylistSystem
{
public:
    virtual ~IMusicPlaylistSystem() = default;

    virtual void showMainMenu() = 0;
    virtual void showPlaylistMenu(IPlaylist *selectedPlaylist) = 0;
    virtual void displaySongs(const IPlaylist *playlist) = 0;
};

#endif
