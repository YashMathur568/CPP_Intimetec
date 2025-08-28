#include "PlaylistManager.h"
#include "Playlist.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

PlaylistManager::~PlaylistManager()
{
    for (auto &playlist : playlists)
    {
        delete playlist.second;
    }
}

bool PlaylistManager::createPlaylist(const std::string &name)
{
    if (playlists.find(name) != playlists.end())
        return false;
    auto *playlist = new Playlist(name);
    playlist->saveToFile(name + ".json");
    playlists[name] = playlist;
    return true;
}

IPlaylist *PlaylistManager::getPlaylist(const std::string &name)
{
    auto iterator = playlists.find(name);
    if (iterator != playlists.end())
        return iterator->second;
    return nullptr;
}

void PlaylistManager::viewAllPlaylists() const
{
    for (const auto &playlist : playlists)
    {
        std::cout << "- " << playlist.first << "\n";
    }
}

void PlaylistManager::loadAllPlaylistsFromDisk()
{
    for (auto &playlist : playlists)
        delete playlist.second;
    playlists.clear();

    for (auto &entry : fs::directory_iterator("."))
    {
        if (entry.path().extension() == ".json")
        {
            auto name = entry.path().stem().string();
            auto *p = new Playlist(name);
            p->loadFromFile(entry.path().string());
            playlists[name] = p;
        }
    }
}

void PlaylistManager::saveAllPlaylistsToDisk() const
{
    for (const auto &playlist : playlists)
    {
        playlist.second->saveToFile(playlist.first + ".json");
    }
}
