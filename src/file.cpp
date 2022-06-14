#include<AirChart/Core/file.h>
#include<fstream>
#include<iostream>

namespace AirChart
{
    std::string File::openFile(const char* fileName)
    {
        std::ifstream file(fileName);

        std::string data;

        if (file.is_open())
        {
            char readChar;

            while ((readChar = file.get()) != EOF)
            {
                data += readChar;
            }
            file.close();
            return data;
        }
        std::cout << "There is no file exists named with: " << fileName << std::endl;
        return NULL;
    }
};