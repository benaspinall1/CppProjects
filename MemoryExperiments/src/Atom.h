#ifndef POINTR3_H
#define POINTR3_H
#pragma once

#include <iostream>
enum AtomType {
	CARBON = 0, OXYGEN, NITROGEN
};

struct Atom {

public:


	Atom();
	Atom(double x, double y, double z, AtomType type);
	void set_coordinates(double x, double y, double z);
	void set_atom_type(const std::string& atom_type);
	AtomType get_atom_type();
	double get_x();
	double get_y();
	double get_z();

private:
	AtomType _type;
	double m_x, m_y, m_z;


};

#endif
