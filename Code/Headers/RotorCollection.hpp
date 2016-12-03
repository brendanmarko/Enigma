#ifndef ROTORCOLLECTION_HPP
#define ROTORCOLLECTION_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <clocale>
#include "Rotor.hpp"
#include "Reflector.hpp"

class RotorCollection
{
	public:
	RotorCollection();
	RotorCollection(Rotor& r1, Rotor& r2, Rotor& r3);

	public:
	void 					addRotor(Rotor&);
	void 					viewAlphabets();
	int	 					numOfRotors();
	Rotor& 					accessRotor(int);
	void 					handleInput(std::string);
	void 					normalIteration(char&);
	void 					reflectorScramble(char&);
	void 					reverseIteration(char&);
	void 					rotorHandler();
	bool					specialChar(char&);

	private:
	Reflector 				reflector;
	int 					num_rotors;
	std::vector<Rotor>		rotors;
	char					c;
	std::string				result;
	std::array<char,5>		special_texts{{' ', '!', '?', '.', ','}};
};

#endif