#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include "IPlaylistManager.h"
#include <unordered_map>
#include <string>

class PlaylistManager : public IPlaylistManager
{
private:
    std::unordered_map<std::string, IPlaylist *> playlists;

public:
    ~PlaylistManager();

    bool createPlaylist(const std::string &name) override;
    bool deletePlaylist(const std::string &name) override;
    IPlaylist *getPlaylist(const std::string &name) override;
    void viewAllPlaylists() const override;
    void loadAllPlaylistsFromDisk() override;
};

#endif
