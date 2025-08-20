#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "fileParser.h"
#include "tinyxml2.h"
#include <iostream>

class xmlParser : public FileParser
{
private:
    tinyxml2::XMLDocument doc;

public:
    void openFile(const std::string &filePath) override;

    void parse() override;

private:
    void traverseElements(tinyxml2::XMLElement *element, const std::string &indent);
};

#endif
