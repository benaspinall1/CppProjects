#include <iostream>
#include <random>
#include <array>
#include "Atom.h"
#include "Timer.h"
#include "FileReader.h"
#include "ProteinSegment.h"





int main() 
{

	FileReader file_reader;
	ProteinSegment s = file_reader.segment_from_file("src\\1A3N.cif", 1, 100);
	std::cout << "Length: " << s.get_length() << std::endl;
	for (int i = 0; i < s.get_length(); i++ ) {
		std::cout << s.coordinates[i].get_atom_type() << " " << s.coordinates[i].get_x() << " " << s.coordinates[i].get_y() << " " << s.coordinates[i].get_z() << "\n";

	}
	std::cout << "Exiting main \n";
}

