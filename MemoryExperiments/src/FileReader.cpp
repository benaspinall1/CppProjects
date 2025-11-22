
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <array>
#include "FileReader.h"
#include "Timer.h"
#include "Atom.h"


FileReader::FileReader(const char* file_name)
{
    Timer time;

    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "ERROR: Could not open file: " << file_name << "\n";
        return;
    }

    std::string line;

    while (std::getline(file, line)) {

        atom_from_line(line);

    }

};

std::array<std::string, 4> FileReader::split(const std::string& file_line) {

    //TODO: Next step is to skip all incidies expect 2,10,11, and 12 then store them in the array to build the atom.
    const int tokens_in_line = 21;
    std::istringstream iss(file_line);
    std::array<std::string, 4> atom_info {};
    std::string token;
    int i = 0;
    while (iss >> token) {
        if (i == 2) {
            atom_info[0] = token;
        }
        else if (i == 10) {
            atom_info[1] = token;
        }
        else if (i == 11) {
            atom_info[2] = token;
        }
        else if (i == 12) {
            atom_info[3] = token;
        }
        i++;
        
    }
    return atom_info;
}

void FileReader::atom_from_line(std::string& file_line) {

    auto atom_info = split(file_line);


    std::string atom_type = atom_info[0];
    double x = std::stod(atom_info[1]); 
    double y = std::stod(atom_info[2]); 
    double z = std::stod(atom_info[3]); 
    std::cout << atom_type << " " << x << " " << y << " " << z << "\n";


}
