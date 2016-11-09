#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include <iostream>
#include "Rotor.hpp"
#include "KeySheet.hpp"

class Enigma
{

	public:
	Enigma();

	private:
	void addRotor(Rotor&);

};

#endif