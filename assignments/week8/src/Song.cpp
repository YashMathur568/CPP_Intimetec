#include "Song.h"

Song::Song(const std::string &path, const std::string &name)
    : filePath(path), name(name) {}

std::string Song::getPath() const
{
    return filePath;
}

std::string Song::getName() const
{
    return name;
}
