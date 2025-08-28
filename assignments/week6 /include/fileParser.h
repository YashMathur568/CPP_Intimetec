#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <string>

class FileParser
{
public:
    virtual ~FileParser() {}

    virtual void openFile(const std::string &filePath) = 0;

    virtual void parse() = 0;
};

#endif
