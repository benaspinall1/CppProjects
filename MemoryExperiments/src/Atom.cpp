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

