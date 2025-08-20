#include <iostream>
#include "input.h"
#include "jsonParser.h"
#include "xmlParser.h"
#include "csvParser.h"

std::string getFileExtension(const std::string &filePath)
{
    int position = filePath.find_last_of('.');
    return (position == std::string::npos) ? "" : filePath.substr(position + 1);
}

int main()
{
    std::string filePath;

    while (true)
    {
        FileParser *parser = nullptr;

        try
        {
            std::cout << "Enter the file path (or type 'exit' to quit): ";
            std::getline(std::cin, filePath);

            if (filePath == "exit")
            {
                std::cout << "Exiting the program..." << std::endl;
                break;
            }

            if (filePath.empty())
            {
                std::cout << "File path cannot be empty!" << std::endl;
                continue;
            }

            std::string fileExtension = getFileExtension(filePath);

            if (fileExtension == "json")
            {
                parser = new jsonParser();
            }
            else if (fileExtension == "xml")
            {
                parser = new xmlParser();
            }
            else if (fileExtension == "csv")
            {
                parser = new csvParser();
            }
            else
            {
                throw std::invalid_argument("Unsupported file type: " + fileExtension);
            }

            parser->openFile(filePath);
            parser->parse();

            delete parser;
            parser = nullptr;
        }
        catch (const std::exception &e)
        {
            std::cout << "Unexpected Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
