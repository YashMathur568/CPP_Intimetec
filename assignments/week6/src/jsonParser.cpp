#include "jsonParser.h"

jsonParser::jsonParser() {}

jsonParser::~jsonParser() {}

void jsonParser::openFile(std::string &filePath)
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

void jsonParser::printJson(nlohmann::json &jsonData, const std::string &indent)
{
    if (jsonData.is_object())
    {
        for (nlohmann::json::iterator iterator = jsonData.begin(); iterator != jsonData.end(); iterator++)
        {
            std::string key = iterator.key();
            nlohmann::json value = iterator.value();

            std::cout << indent << key << ": ";
            if (value.is_primitive())
            {
                std::cout << value << std::endl;
            }
            else
            {
                std::cout << std::endl;
                printJson(value, indent + "  ");
            }
        }
    }
    else if (jsonData.is_array())
    {
        int arraySize = jsonData.size();

        for (int i = 0; i < arraySize; ++i)
        {
            std::cout << indent << "[" << i << "]: ";
            nlohmann::json element = jsonData[i];

            if (element.is_primitive())
            {
                std::cout << element << std::endl;
            }
            else
            {
                std::cout << std::endl;
                printJson(element, indent + "  ");
            }
        }
    }
    else
    {
        std::cout << indent << jsonData << std::endl;
    }
}
