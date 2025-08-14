#include <iostream>
#include "jsonParser.h"
#include "xmlParser.h"
#include "csvParser.h"

void flushInputBuffer()
{
    while (getchar() != '\n')
    {
    };
}

int getValidatedInt()
{
    int value;
    while (true)
    {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n' || value <= 0)
        {
            std::cout << "Invalid input. Please enter a valid positive and non-zero number.\n";
            std::cin.clear();
            flushInputBuffer();
        }
        else
        {
            flushInputBuffer();
            return value;
        }
    }
}

void displayMenu()
{
    std::cout << "Hi, What do you want to parse today?" << std::endl;
    std::cout << "1.) JSON File" << std::endl;
    std::cout << "2.) XML File" << std::endl;
    std::cout << "3.) CSV File" << std::endl;
    std::cout << "4.) Exit" << std::endl;
    std::cout << "Choose an option (1-4): ";
}

int main()
{
    int choice;
    std::string filePath;

    while (true)
    {
        FileParser *parser = nullptr;

        try
        {
            displayMenu();
            choice = getValidatedInt();

            if (choice == 4)
            {
                std::cout << "Exiting program..." << std::endl;
                break;
            }

            switch (choice)
            {
            case 1:
                parser = new jsonParser();
                break;
            case 2:
                parser = new xmlParser();
                break;
            case 3:
                parser = new csvParser();
                break;
            default:
                std::cout << "Invalid choice! Please choose again." << std::endl;
                continue;
            }

            std::cout << "Enter the file path: ";
            std::getline(std::cin, filePath);

            if (filePath.empty())
            {
                throw std::invalid_argument("File path cannot be empty");
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
        catch (...)
        {
            std::cout << "Unknown error occurred!" << std::endl;
        }

        if (parser)
        {
            delete parser;
        }
    }

    return 0;
}
