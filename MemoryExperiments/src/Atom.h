#ifndef POINTR3_H
#define POINTR3_H
#pragma once

#include <iostream>

struct Atom {

public:

	enum AtomType {
		CARBON = 0, OXYGEN, NITROGEN
	};

	Atom();
	Atom(double x, double y, double z, AtomType type);

	void set_coordinates(double x, double y, double z) {
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void set_atom_type(std::string& atom_type) {
		if (atom_type == "C") {
			_type = CARBON;
		}
		else if (atom_type == "N") {
			_type = NITROGEN;
		}
		else if (atom_type == "O") {
			_type = OXYGEN;
		}

	}

private:
	AtomType _type;
	double m_x, m_y, m_z;


};

#endif
