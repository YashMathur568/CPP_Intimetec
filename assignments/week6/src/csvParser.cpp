#include "csvParser.h"

csvParser::csvParser() : totalRows(0) {}

csvParser::~csvParser() {}

void csvParser::openFile(std::string &filePath)
{
    try
    {
        file.open(filePath);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open the CSV file: " + filePath);
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Error opening CSV file: " << e.what() << std::endl;
        throw;
    }
}

void csvParser::parse()
{
    std::string line;
    int rowIndex = 0;

    while (std::getline(file, line) && rowIndex < MAX_ROWS)
    {
        processLine(line, rowIndex);
        ++rowIndex;
    }

    totalRows = rowIndex;
    calculateColumnWidths();

    for (int currentRow = 0; currentRow < totalRows; ++currentRow)
    {
        printRow(data[currentRow], MAX_COLS);
    }

    file.close();
}

void csvParser::processLine(std::string &line, int rowIndex)
{
    int columnIndex = 0;
    bool insideQuotes = false;
    std::string currentCell;

    for (int charIndex = 0; charIndex < line.size(); ++charIndex)
    {
        char currentChar = line[charIndex];

        if (currentChar == '"' && (charIndex == 0 || line[charIndex - 1] != '\\'))
        {
            insideQuotes = !insideQuotes;
        }
        else if (currentChar == ',' && !insideQuotes)
        {
            data[rowIndex][columnIndex++] = currentCell;
            currentCell.clear();
        }
        else
        {
            currentCell += currentChar;
        }
    }

    data[rowIndex][columnIndex] = currentCell;
}

void csvParser::calculateColumnWidths()
{
    for (int columnIndex = 0; columnIndex < MAX_COLS; ++columnIndex)
    {
        columnWidths[columnIndex] = 0;
    }

    for (int rowIndex = 0; rowIndex < totalRows; ++rowIndex)
    {
        for (int columnIndex = 0; columnIndex < MAX_COLS && data[rowIndex][columnIndex] != ""; ++columnIndex)
        {
            columnWidths[columnIndex] = std::max(columnWidths[columnIndex], (int)(data[rowIndex][columnIndex].length()));
        }
    }
}

void csvParser::printRow(std::string row[], int rowSize)
{
    for (int columnIndex = 0; columnIndex < rowSize && row[columnIndex] != ""; ++columnIndex)
    {
        std::cout << row[columnIndex];

        int spacePadding = columnWidths[columnIndex] - row[columnIndex].length();
        for (int spaceIndex = 0; spaceIndex < spacePadding; ++spaceIndex)
        {
            std::cout << " ";
        }

        if (columnIndex != rowSize - 1 && row[columnIndex + 1] != "")
        {
            std::cout << " | ";
        }
    }
    std::cout << std::endl;
}
