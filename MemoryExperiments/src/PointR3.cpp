#include "PointR3.h"
#include <string>


PointR3::PointR3(std::string& name) {
	x = 1;
	y = 2;
	z = 3;
	std::cout << name << " created." << std::endl;
}

void PointR3::Print() {
	std::cout << x << " " << y << " " << z;
}
