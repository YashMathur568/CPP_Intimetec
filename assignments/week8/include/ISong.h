#ifndef ISONG_H
#define ISONG_H

#include <string>

class ISong
{
public:
    virtual ~ISong() = default;
    virtual std::string getPath() const = 0;
    virtual std::string getName() const = 0;
};

#endif
