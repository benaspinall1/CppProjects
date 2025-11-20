#include <iostream>
#include <random>
#include <array>
#include "PointR3.h"
#include "Timer.h"
#include "FileReader.h"




int main() 
{
	Timer time;
	std::cout << "Memory Experiments Project" << std::endl;

	std::string point_name = "Point 1";
	PointR3 point(point_name);


	FileReader file_reader("src\\1A3N.cif");


	point.Print();

}

