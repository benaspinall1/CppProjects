#include "Atom.h"
#include <string>



Atom::Atom(double x, double y, double z, AtomType atom_type)
	:m_x(x), m_y(y), m_z(z), _type(atom_type)
{
	
}

Atom::Atom()
	: _type(CARBON), m_x(0.0), m_y(0.0), m_z(0.0)
{
}

double Atom::get_x() { return m_x; }
double Atom::get_y() { return m_y; }
double Atom::get_z() { return m_z; }
AtomType Atom::get_atom_type() { return _type; }

void Atom::set_coordinates(double x, double y, double z) {
	m_x = x;
	m_y = y;
	m_z = z;
}

void Atom::set_atom_type(const std::string& atom_type) {
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

