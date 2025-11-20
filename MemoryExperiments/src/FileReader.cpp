
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <filesystem>
#include "FileReader.h"


FileReader::FileReader(const char* file_name)
{
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "ERROR: Could not open file: " << file_name << "\n";
        std::cout << "Current path: " << std::filesystem::current_path() << "\n";
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.starts_with("ATOM")) {
            std::cout << line << "\n";
        }
    }

    std::cout << "After Read" << "\n";



};