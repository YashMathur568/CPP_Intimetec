#ifndef CSVPARSER_H
#define CSVPARSER_H
#include "fileParser.h"
#include <iostream>
#include <fstream>
#include <string>
#define MAX_ROWS 100
#define MAX_COLS 20

class csvParser : public FileParser
{
private:
    std::ifstream file;
    std::string data[MAX_ROWS][MAX_COLS];
    int columnWidths[MAX_COLS];
    int totalRows;

public:
    csvParser();
    ~csvParser();
    void openFile(std::string &filePath) override;
    void parse() override;

private:
    void printRow(std::string row[], int rowSize);
    void processLine(std::string &line, int rowIndex);
    void calculateColumnWidths();
};

#endif