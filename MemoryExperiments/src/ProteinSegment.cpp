// I am creating this file because I want to quantify the cost of allocating memory of the stack versus the heap. 

#include "ProteinSegment.h"
#include "Atom.h"

#include <iostream>

ProteinSegment::ProteinSegment()
	: _start_index(0), _end_index(0), _coordinates(new Atom[5000])
{

}
ProteinSegment::~ProteinSegment()
{
	delete[] _coordinates;
}