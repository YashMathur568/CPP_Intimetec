#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "IPlaylist.h"
#include <string>
#include <vector>

class Playlist : public IPlaylist
{
private:
    std::string name;
    std::vector<ISong *> songs;

public:
    Playlist(const std::string &n);
    ~Playlist();

    void addSong(ISong *song) override;
    void removeSongAt(int index) override;
    void moveSongUp(int index) override;
    void moveSongDown(int index) override;
    void loadFromFile(const std::string &filename) override;
    void saveToFile(const std::string &filename) const override;
    const std::vector<ISong *> &getSongs() const override;
    std::string getName() const override;
};

#endif
