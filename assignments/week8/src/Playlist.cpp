#include "Playlist.h"
#include "Song.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <algorithm>

using json = nlohmann::json;

Playlist::Playlist(const std::string &name) : name(name) {}

Playlist::~Playlist()
{
    for (auto *song : songs)
    {
        delete song;
    }
}

void Playlist::addSong(ISong *song)
{
    songs.push_back(song);
    saveToFile(name + ".json");
}

void Playlist::removeSongAt(int index)
{
    if (index >= 0 && index < (int)songs.size())
    {
        delete songs[index];
        songs.erase(songs.begin() + index);
        saveToFile(name + ".json");
    }
}

void Playlist::moveSongUp(int index)
{
    if (index > 0 && index < (int)songs.size())
    {
        std::swap(songs[index], songs[index - 1]);
        saveToFile(name + ".json");
    }
}

void Playlist::moveSongDown(int index)
{
    if (index >= 0 && index < (int)songs.size() - 1)
    {
        std::swap(songs[index], songs[index + 1]);
        saveToFile(name + ".json");
    }
}

void Playlist::loadFromFile(const std::string &filename)
{
    for (auto *song : songs)
        delete song;
    songs.clear();

    std::ifstream File(filename);
    if (!File.is_open())
        return;

    json j;
    File >> j;
    name = j.value("name", "");

    for (auto &song : j["songs"])
    {
        songs.push_back(new Song(song["path"], song["name"]));
    }
}

void Playlist::saveToFile(const std::string &filename) const
{
    json j;
    j["name"] = name;
    j["songs"] = json::array();
    for (auto *song : songs)
    {
        j["songs"].push_back({{"path", song->getPath()}, {"name", song->getName()}});
    }
    std::ofstream out(filename);
    out << j.dump(4);
}

const std::vector<ISong *> &Playlist::getSongs() const
{
    return songs;
}

std::string Playlist::getName() const
{
    return name;
}
