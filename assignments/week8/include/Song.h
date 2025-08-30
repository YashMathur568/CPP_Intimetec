#ifndef SONG_H
#define SONG_H

#include "ISong.h"
#include <string>

class Song : public ISong
{
private:
    std::string filePath;
    std::string name;

public:
    Song(const std::string &path, const std::string &name);

    std::string getPath() const override;
    std::string getName() const override;
};

#endif
