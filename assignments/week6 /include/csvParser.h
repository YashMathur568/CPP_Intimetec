#ifndef CSVPARSER_H
#define CSVPARSER_H
#include "fileParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class csvParser : public FileParser
{
private:
    std::ifstream file;
    std::string **data;
    int *columnWidths;
    int *rowSizes;
    int totalRows;

public:
    csvParser();
    ~csvParser();
    void openFile(const std::string &filePath) override;
    void parse() override;

private:
    void printRow(std::string *row, int rowSize);
    void processLine(const std::string &line, int rowIndex);
    void calculateColumnWidths();
    void cleanupOfResources();
};

#endif
