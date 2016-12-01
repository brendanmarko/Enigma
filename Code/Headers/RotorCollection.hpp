#ifndef ROTORCOLLECTION_HPP
#define ROTORCOLLECTION_HPP

#include <vector>
#include <algorithm>
#include "Rotor.hpp"

class RotorCollection
{
	public:
	RotorCollection();
	RotorCollection(Rotor& r1, Rotor& r2, Rotor& r3);

	public:
	void 				addRotor(Rotor&);
	void 				viewAlphabets();
	int	 				numOfRotors();
	Rotor& 				accessRotor(int);
	void 				handleLetter(char);

	private:
	int 				num_rotors;
	std::vector<Rotor> 	rotors;
};

#endif