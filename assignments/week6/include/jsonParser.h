#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "fileParser.h"
#include "./json.hpp"
#include <fstream>
#include <iostream>

class jsonParser : public FileParser
{
private:
    nlohmann::json parsedData;

public:
    jsonParser();
    ~jsonParser();

    void openFile(const std::string &filePath) override;

    void parse() override;

private:
    void printJson(const nlohmann::json &data, const std::string &indent);
};

#endif
