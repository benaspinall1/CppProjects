#ifndef PROTEINSEGMENT_H
#define PROTEINSEGMENT_H
#pragma once

#include <array>
#include "Atom.h"


class ProteinSegment {
public:
	ProteinSegment();
	ProteinSegment(int start, int end);
	ProteinSegment(const ProteinSegment& other);
	ProteinSegment(ProteinSegment&& other) noexcept;
	ProteinSegment& operator=(const ProteinSegment& other);
	ProteinSegment& operator=(ProteinSegment&& other) noexcept;
	~ProteinSegment();
	Atom* coordinates; 
	void set_length(int length);
	int get_length() const;

private:
	int start_index, end_index;
	int coordinates_length;
};


#endif