#ifndef ROTORCOLLECTION_HPP
#define ROTORCOLLECTION_HPP

#include <vector>
#include "Rotor.hpp"

class RotorCollection
{

	public:
	RotorCollection(Rotor& r1, Rotor& r2, Rotor& r3);

	public:
	void 	addRotor(Rotor&);
	void 	viewAlphabets();
	int	 	numOfRotors();

	private:
	int 					num_rotors;
	std::vector<Rotor> 		rotors;

};

#endif