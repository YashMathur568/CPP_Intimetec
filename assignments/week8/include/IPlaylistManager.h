#ifndef IPLAYLISTMANAGER_H
#define IPLAYLISTMANAGER_H

#include <string>
#include "IPlaylist.h"

class IPlaylistManager
{
public:
    virtual ~IPlaylistManager() = default;

    virtual bool createPlaylist(const std::string &name) = 0;
    virtual bool deletePlaylist(const std::string &name) = 0;
    virtual IPlaylist *getPlaylist(const std::string &name) = 0;
    virtual void viewAllPlaylists() const = 0;
    virtual void loadAllPlaylistsFromDisk() = 0;
};

#endif
