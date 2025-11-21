
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

        Atom* a = atom_from_line(line);

    }

};

std::array<std::string, 4> FileReader::split(const std::string& file_line) {

    //TODO: Next step is to skip all incidies expect 0,10,11, and 12 then store them in the array to build the atom.
    std::istringstream iss(file_line);
    std::vector<std::string> v;
    std::string token;
    while (iss >> token) v.push_back(token);
    return v;
}

Atom* FileReader::atom_from_line(std::string& file_line) {


    auto atom_info = split(file_line);

    std::cout << "Length of line: " << v.size() << std::endl;

    // TODO: Change these incides to 1, 2, 3 and reserve 0 for the atom type
    double x = std::stod(atom_info[10]); // -14.635
    double y = std::stod(atom_info[11]); // -5.789
    double z = std::stod(atom_info[12]); //  8.403
    std::cout << x << " " << y << " " << z << "\n";


    Atom* atom = new Atom(1.1,2.2,4.4, Atom::CARBON);
    return atom;
}
