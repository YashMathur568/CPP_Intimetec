#include <iostream>
#include <fstream>
#include <string>

int main()
{
    try
    {
        std::ofstream fout("data.txt", std::ios::out | std::ios::trunc);
        if (!fout)
        {
            throw std::runtime_error("Could not open file for writing.");
        }
        fout << "Line 1: My name is yash\n";
        fout << "Line 2: c++ training\n";
        fout << "Line 3: Good weather\n";
        fout.close();

        std::cout << "written some data to file.\n";

        std::ifstream fin("data.txt", std::ios::in);
        if (!fin)
        {
            throw std::runtime_error("Could not open file for reading.");
        }

        std::string line;
        std::cout << "Reading full file:\n";
        while (std::getline(fin, line))
        {
            std::cout << line << std::endl;
        }

        fin.clear();
        fin.seekg(12);

        std::string fromfilepointer;
        std::getline(fin, fromfilepointer);
        std::cout << fromfilepointer << "\n";

        int pos = fin.tellg();
        std::cout << "Current position in file: " << pos << "\n";

        fin.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
