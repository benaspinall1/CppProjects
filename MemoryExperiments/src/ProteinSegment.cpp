// I am creating this file because I want to quantify the cost of allocating memory of the stack versus the heap. 

#include "ProteinSegment.h"
#include "Atom.h"

#include <iostream>


ProteinSegment::ProteinSegment()
	: start_index(0), end_index(0), coordinates_length(0), coordinates(nullptr)
{
	std::cout << "ProteinSegment default constructor called\n";

}

ProteinSegment::ProteinSegment(int start, int end)
	: start_index(start), end_index(end), coordinates_length(end - start + 1), coordinates(new Atom[100])
{
	std::cout << "ProteinSegment constructor called\n";

}

ProteinSegment::ProteinSegment(const ProteinSegment& other)
	: start_index(other.start_index), end_index(other.end_index), coordinates(nullptr), coordinates_length(other.coordinates_length)
{
	std::cout << "ProteinSegment copy constructor called\n";
	coordinates = new Atom[coordinates_length];
	for (int i = 0; i < coordinates_length; ++i) {
		coordinates[i] = other.coordinates ? other.coordinates[i] : Atom{};
	}
}


ProteinSegment::ProteinSegment(ProteinSegment&& other) noexcept
	: start_index(other.start_index), end_index(other.end_index), coordinates(other.coordinates), coordinates_length(other.coordinates_length)
{
	std::cout << "ProteinSegment move constructor called\n";
	other.coordinates = nullptr;
	other.start_index = 0;
	other.end_index = 0;
	other.coordinates_length = 0;
}

ProteinSegment& ProteinSegment::operator=(const ProteinSegment& other)
{
	if (this == &other) return *this;
	std::cout << "ProteinSegment copy assignment operator called\n";
	start_index = other.start_index;
	end_index = other.end_index;

	if (!coordinates || coordinates_length != other.coordinates_length) {
		delete[] coordinates;
		coordinates = new Atom[other.coordinates_length];
	}
	coordinates_length = other.coordinates_length;
	for (int i = 0; i < coordinates_length; ++i) {
		coordinates[i] = other.coordinates ? other.coordinates[i] : Atom{};
	}
	return *this;
}

ProteinSegment& ProteinSegment::operator=(ProteinSegment&& other) noexcept
{
	if (this == &other) return *this;

	std::cout << "ProteinSegment move assignment operator called\n";
	delete[] coordinates;

	start_index = other.start_index;
	end_index = other.end_index;
	coordinates = other.coordinates;
	coordinates_length = other.coordinates_length;

	other.coordinates = nullptr;
	other.start_index = 0;
	other.end_index = 0;
	other.coordinates_length = 0;
	return *this;
}
ProteinSegment::~ProteinSegment()
{
	std::cout << "ProteinSegment destructor called\n";
	delete[] coordinates;
	coordinates = nullptr;
}

void ProteinSegment::set_length(int length)
{
	coordinates_length = length;
}

int ProteinSegment::get_length() const
{
	return coordinates_length;
}