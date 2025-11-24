
#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include "FileReader.h"
#include "Atom.h"
#include "ProteinSegment.h"


const ProteinSegment FileReader::segment_from_file(const char* file_name, int start, int end) {

    std::ifstream file(file_name);

    std::cout << "About to create a segment \n";
    const ProteinSegment segment(start, end);
    
    if (!file.is_open()) {
        std::cerr << "ERROR: Could not open file: " << file_name << "\n";
        return ProteinSegment{};
    }

    std::string line;
    int i = 0;
    while (i < segment.get_length() && std::getline(file, line)) {
        auto info = split(line);
        Atom atom  = atom_from_line(line);
        segment.coordinates[i] = atom;
        i++;
    }

    std::cout << "Done creating segment \n";
    /*
    I learned that this only calls the move constructor when the function doesn't return a const object
    because of some called name return value optimization. I will look into that concept next. I will then create 
    more version of this function to further my experiments.
    */
    return segment;
}



std::array<std::string, 4> FileReader::split(const std::string& file_line) {

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

Atom FileReader::atom_from_line(const std::string& file_line) {

    auto atom_info = split(file_line);

    std::string atom_type = atom_info[0];
    double x = 0.0, y = 0.0, z = 0.0;
    x = std::stod(atom_info[1]);
    y = std::stod(atom_info[2]);
    z = std::stod(atom_info[3]);
    //std::cout << atom_info[0] << " " << atom_info[1] << " " << atom_info[2] << " " << atom_info[3] << "\n";

    Atom atom;
    atom.set_atom_type(atom_type);
    atom.set_coordinates(x, y, z);

    return atom;
}
