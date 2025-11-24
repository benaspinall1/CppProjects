#ifndef FILEREADER_H
#define FILEREADER_H
#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <array>
#include "Atom.h"
#include "ProteinSegment.h"


class FileReader {

public:
	const ProteinSegment segment_from_file(const char* file_name, int start, int end);

private:
	std::array<std::string, 4> split(const std::string& file_line);
	Atom atom_from_line(const std::string& file_line);
};


#endif