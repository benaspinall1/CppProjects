
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <array>
#include <sstream>
#include "FileReader.h"
#include "Atom.h"
#include "ProteinSegment.h"



ProteinSegment FileReader::segment_from_file(const char* file_name) {

    std::ifstream file(file_name);
    ProteinSegment segment;
    if (!file.is_open()) {
        std::cerr << "ERROR: Could not open file: " << file_name << "\n";
        return ProteinSegment{};
    }

    std::string line;

    while (std::getline(file, line)) {

        Atom atom  = atom_from_line(line);
        // add to the protein segment coordinates
    }


    return segment;
}



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

Atom FileReader::atom_from_line(std::string& file_line) {

    auto atom_info = split(file_line);


    std::string atom_type = atom_info[0];


    double x = std::stod(atom_info[1]); 
    double y = std::stod(atom_info[2]); 
    double z = std::stod(atom_info[3]); 
    std::cout << atom_type << " " << x << " " << y << " " << z << "\n";

    int type = 0;
    Atom atom;
    atom.set_atom_type(atom_type);
    atom.set_coordinates(x, y, z);
    

    return atom;
}
