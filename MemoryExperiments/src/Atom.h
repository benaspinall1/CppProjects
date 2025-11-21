#ifndef POINTR3_H
#define POINTR3_H
#pragma once

#include <iostream>

struct Atom {

public:


	enum AtomType {
		CARBON = 0, OXYGEN, NITROGEN
	};

	Atom(double x, double y, double z, AtomType type);

private:
	AtomType _type;
	double m_x, m_y, m_z;


};

#endif
