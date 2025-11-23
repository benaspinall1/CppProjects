#ifndef TIMER_H
#define TIMER_H
#pragma once

#include <array>
#include "Atom.h"


class ProteinSegment {
public:
	ProteinSegment();
	~ProteinSegment();

private:
	int _start_index, _end_index;
	Atom* _coordinates; 
	// I know that "I shouldnt be using raw pointers" but its for science. 
};


#endif