#include "xmlParser.h"

xmlParser::xmlParser() {}

xmlParser::~xmlParser() {}

void xmlParser::openFile(const std::string &filePath)
{
    try
    {
        tinyxml2::XMLError result = doc.LoadFile(filePath.c_str());
        if (result != tinyxml2::XML_SUCCESS)
        {
            throw std::runtime_error("Failed to load XML file: " + filePath + " (Error code: " + std::to_string(result) + ")");
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "XML file error: " << e.what() << std::endl;
        throw;
    }
}

void xmlParser::parse()
{
    std::cout << "Parsing XML file..." << std::endl;

    tinyxml2::XMLElement *rootElement = doc.RootElement();
    if (rootElement)
    {
        traverseElements(rootElement, "");
    }
    else
    {
        std::cout << "No root element found in XML." << std::endl;
    }
}

void xmlParser::traverseElements(tinyxml2::XMLElement *currentElement, const std::string &indentation)
{

    std::cout << indentation << currentElement->Name();

    const tinyxml2::XMLAttribute *currentAttribute = currentElement->FirstAttribute();
    if (currentAttribute)
    {
        std::cout << " (";
        while (currentAttribute)
        {
            std::cout << currentAttribute->Name() << "=\"" << currentAttribute->Value() << "\"";
            currentAttribute = currentAttribute->Next();
            if (currentAttribute)
                std::cout << ", ";
        }
        std::cout << ")";
    }

    std::cout << std::endl;

    if (currentElement->GetText())
    {
        std::cout << indentation << "  Text: " << currentElement->GetText() << std::endl;
    }

    tinyxml2::XMLElement *childElement = currentElement->FirstChildElement();
    if (childElement)
    {
        int childIndex = 0;
        while (childElement != nullptr)
        {
            std::cout << indentation << "  [" << childIndex++ << "] ";
            traverseElements(childElement, indentation + "  ");
            childElement = childElement->NextSiblingElement();
        }
    }
}
