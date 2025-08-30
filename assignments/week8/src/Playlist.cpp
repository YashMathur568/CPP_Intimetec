#include "Playlist.h"
#include "Song.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <algorithm>

using json = nlohmann::json;

Playlist::Playlist(const std::string &name, bool ownsSongs)
    : name(name), ownsSongs(ownsSongs) {}

Playlist::~Playlist()
{
    if (ownsSongs)
    {
        for (auto *song : songs)
            delete song;
    }
}

void Playlist::addSong(ISong *song)
{
    songs.push_back(song);
    saveToFile("../Playlists/" + name + ".json");
}

void Playlist::removeSongAt(int index)
{
    if (index >= 0 && index < (int)songs.size())
    {
        if (ownsSongs)
        {
            delete songs[index];
        }
        songs.erase(songs.begin() + index);
        saveToFile("../Playlists/" + name + ".json");
    }
}

void Playlist::moveSongUp(int index)
{
    if (index > 0 && index < songs.size())
    {
        std::swap(songs[index], songs[index - 1]);
        saveToFile("../Playlists/" + name + ".json");
    }
}

void Playlist::moveSongDown(int index)
{
    if (index >= 0 && index < songs.size() - 1)
    {
        std::swap(songs[index], songs[index + 1]);
        saveToFile("../Playlists/" + name + ".json");
    }
}

void Playlist::loadFromFile(const std::string &filename)
{

    std::ifstream File(filename);
    if (!File.is_open())
    {
        return;
    }

    json playlistData;
    File >> playlistData;
    name = playlistData.value("name", "");

    for (auto &song : playlistData["songs"])
    {
        songs.push_back(new Song(song["path"], song["name"]));
    }
}

void Playlist::saveToFile(const std::string &filename) const
{
    json playlistData;
    playlistData["name"] = name;
    playlistData["songs"] = json::array();
    for (auto *song : songs)
    {
        playlistData["songs"].push_back({{"path", song->getPath()}, {"name", song->getName()}});
    }
    std::ofstream out(filename);
    out << playlistData.dump(4);
}

const std::vector<ISong *> &Playlist::getSongs() const
{
    return songs;
}

std::string Playlist::getName() const
{
    return name;
}
