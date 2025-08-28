#ifndef IPLAYLIST_H
#define IPLAYLIST_H

#include <string>
#include <vector>
#include "ISong.h"

class IPlaylist
{
public:
    virtual ~IPlaylist() = default;

    virtual void addSong(ISong *song) = 0;
    virtual void removeSongAt(int index) = 0;
    virtual void moveSongUp(int index) = 0;
    virtual void moveSongDown(int index) = 0;
    virtual void loadFromFile(const std::string &filename) = 0;
    virtual void saveToFile(const std::string &filename) const = 0;
    virtual const std::vector<ISong *> &getSongs() const = 0;
    virtual std::string getName() const = 0;
};

#endif
