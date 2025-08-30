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
    {
        return false;
    }

    auto *playlist = new Playlist(name);

    if (!fs::exists("../Playlists"))
    {
        fs::create_directory("../Playlists");
    }

    playlist->saveToFile("../Playlists/" + name + ".json");
    playlists[name] = playlist;
    return true;
}

bool PlaylistManager::deletePlaylist(const std::string &name)
{
    auto iterator = playlists.find(name);
    if (iterator == playlists.end())
    {
        return false;
    }

    delete iterator->second;
    playlists.erase(iterator);

    std::string filename = "../Playlists/" + name + ".json";
    try
    {
        if (fs::exists(filename))
        {
            fs::remove(filename);
            std::cout << "Playlist file deleted from disk.\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Warning: Could not delete playlist file: " << e.what() << "\n";
    }

    return true;
}

IPlaylist *PlaylistManager::getPlaylist(const std::string &name)
{
    auto iterator = playlists.find(name);
    if (iterator != playlists.end())
    {
        return iterator->second;
    }
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
    for (auto &file : fs::directory_iterator("../Playlists"))
    {
        if (file.path().extension() == ".json")
        {
            auto name = file.path().stem().string();
            auto *playlist = new Playlist(name);
            playlist->loadFromFile(file.path().string());
            playlists[name] = playlist;
        }
    }
}
