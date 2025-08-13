#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main()
{
    std::ifstream file("data.json");
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open data.json\n";
        return 1;
    }

    json j;
    file >> j;

    for (int i = 0; i < j["employees"].size(); i++)
    {
        json emp = j["employees"][i];

        std::cout << "ID: " << emp["id"] << "\n";
        std::cout << "Name: " << emp["name"] << "\n";
        std::cout << "Department: " << emp["department"] << "\n";
        std::cout << "Salary: " << emp["salary"] << "\n";
        std::cout << " ***************** \n";
    }

    return 0;
}
