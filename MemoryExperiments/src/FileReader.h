#ifndef FILEREADER_H
#define FILEREADER_H
#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Atom.h"



class FileReader {

public:
	FileReader(const char* file_name);

	void atom_from_line(std::string& file_line);

	std::array<std::string, 4> split(const std::string& s);



};


#endif