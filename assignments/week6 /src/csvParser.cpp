#include "csvParser.h"

csvParser::csvParser() : data(nullptr), columnWidths(nullptr), rowSizes(nullptr), totalRows(0) {}

csvParser::~csvParser()
{
    cleanupOfResources();
}

void csvParser::openFile(const std::string &filePath)
{
    file.open(filePath);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filePath);
    }
}

void csvParser::parse()
{
    if (!file.is_open())
    {
        throw std::runtime_error("No file is open for parsing");
    }

    std::string currentLine;
    totalRows = 0;
    while (std::getline(file, currentLine))
    {
        if (!currentLine.empty())
        {
            totalRows++;
        }
    }
    if (totalRows == 0)
    {
        std::cout << "File is empty or contains no valid rows" << std::endl;
        return;
    }
    file.clear();
    file.seekg(0);

    data = new std::string *[totalRows];
    rowSizes = new int[totalRows];

    int rowIndex = 0;
    while (std::getline(file, currentLine) && rowIndex < totalRows)
    {
        if (!currentLine.empty())
        {
            processLine(currentLine, rowIndex);
            rowIndex++;
        }
    }
    calculateColumnWidths();
    std::cout << "\nParsed Data:\n"
              << std::endl;

    for (int rowIndex = 0; rowIndex < totalRows; rowIndex++)
    {
        printRow(data[rowIndex], rowSizes[rowIndex]);
    }
}

void csvParser::processLine(const std::string &line, int rowIndex)
{
    int columnCount = 1;
    bool inQuotes = false;
    for (int charIndex = 0; charIndex < line.length(); charIndex++)
    {
        if (line[charIndex] == '"')
        {
            inQuotes = !inQuotes;
        }
        else if (line[charIndex] == ',' && !inQuotes)
        {
            columnCount++;
        }
    }

    rowSizes[rowIndex] = columnCount;
    data[rowIndex] = new std::string[columnCount];

    int columnIndex = 0;
    inQuotes = false;
    std::string currentCell = "";

    for (int charIndex = 0; charIndex < line.length(); charIndex++)
    {
        char currentChar = line[charIndex];
        if (currentChar == '"')
        {
            inQuotes = !inQuotes;
        }
        else if (currentChar == ',' && !inQuotes)
        {
            data[rowIndex][columnIndex] = currentCell;
            columnIndex++;
            currentCell = "";
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
    if (totalRows == 0)
    {
        return;
    }
    int maxColumns = 0;
    for (int rowIndex = 0; rowIndex < totalRows; rowIndex++)
    {
        if (rowSizes[rowIndex] > maxColumns)
        {
            maxColumns = rowSizes[rowIndex];
        }
    }

    columnWidths = new int[maxColumns];
    for (int columnIndex = 0; columnIndex < maxColumns; columnIndex++)
    {
        columnWidths[columnIndex] = 0;
    }
    for (int rowIndex = 0; rowIndex < totalRows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < rowSizes[rowIndex]; columnIndex++)
        {
            int cellLength = data[rowIndex][columnIndex].length();
            if (cellLength > columnWidths[columnIndex])
            {
                columnWidths[columnIndex] = cellLength;
            }
        }
    }
}

void csvParser::printRow(std::string *row, int rowSize)
{
    for (int columnIndex = 0; columnIndex < rowSize; columnIndex++)
    {
        int width = columnWidths[columnIndex];
        std::cout << std::left << std::setw(width + 2) << row[columnIndex];

        if (columnIndex < rowSize - 1)
        {
            std::cout << "| ";
        }
    }
    std::cout << std::endl;
}

void csvParser::cleanupOfResources()
{
    for (int rowIndex = 0; rowIndex < totalRows; rowIndex++)
    {
        if (data[rowIndex] != nullptr)
        {
            delete[] data[rowIndex];
            data[rowIndex] = nullptr;
        }
    }
    delete[] data;
    data = nullptr;

    if (columnWidths != nullptr)
    {
        delete[] columnWidths;
        columnWidths = nullptr;
    }
    if (rowSizes != nullptr)
    {
        delete[] rowSizes;
        rowSizes = nullptr;
    }
}
