#ifndef ROTORCOLLECTION_HPP
#define ROTORCOLLECTION_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "Rotor.hpp"
#include "Reflector.hpp"

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
	void 				handleInput(std::string);
	void 				normalIteration(char&);
	void 				reflectorScramble(char&);
	void 				reverseIteration(char&);

	private:
	Reflector 			reflector;
	int 				num_rotors;
	std::vector<Rotor> 	rotors;
	char 				c;
};

#endif