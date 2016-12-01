#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include <iostream>
#include "Rotor.hpp"
#include "KeySheet.hpp"
#include "RotorCollection.hpp"

class Enigma
{

	public:
	Enigma();

	private:
	void 				buildRotors();

	private:
	std::string 		output_file;

};

#endif