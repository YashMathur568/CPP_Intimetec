#include "jsonParser.h"

jsonParser::jsonParser() {}

jsonParser::~jsonParser() {}

void jsonParser::openFile(const std::string &filePath)
{
    try
    {
        std::ifstream file(filePath);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open the JSON file: " + filePath);
        }
        file >> parsedData;
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Error reading JSON file: " + std::string(e.what()));
    }
}

void jsonParser::parse()
{
    std::cout << "Parsing JSON file..." << std::endl;
    printJson(parsedData, "");
}

void jsonParser::printJson(const nlohmann::json &jsonData, const std::string &indent)
{
    if (jsonData.is_object())
    {
        for (nlohmann::json::const_iterator objIterator = jsonData.begin(); objIterator != jsonData.end(); ++objIterator)
        {
            std::cout << indent << objIterator.key() << ": ";
            if (objIterator.value().is_primitive())
            {
                std::cout << objIterator.value() << std::endl;
            }
            else
            {
                std::cout << std::endl;
                printJson(objIterator.value(), indent + "  ");
            }
        }
    }
    else if (jsonData.is_array())
    {
        int elementIndex = 0;
        for (nlohmann::json::const_iterator arrIterator = jsonData.begin(); arrIterator != jsonData.end(); ++arrIterator)
        {
            std::cout << indent << "[" << elementIndex++ << "]: ";
            if (arrIterator->is_primitive())
            {
                std::cout << *arrIterator << std::endl;
            }
            else
            {
                std::cout << std::endl;
                printJson(*arrIterator, indent + "  ");
            }
        }
    }
    else
    {
        std::cout << indent << jsonData << std::endl;
    }
}
