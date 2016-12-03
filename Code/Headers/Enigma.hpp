#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include <vector>
#include <sstream>
#include <iostream>
#include "Rotor.hpp"
#include "KeySheet.hpp"
#include "Plugboard.hpp"
#include "RotorCollection.hpp"

class Enigma
{
	public:
	Enigma();

	public:
	void 				buildRotors(std::vector<int>);
	void 				addStartPos(RotorCollection&);

	private:
	std::string 		plaintext;
	std::string 		output_file;
	std::string 		sheet_number;
	Rotor 				l_rotor, m_rotor, r_rotor;
	RotorCollection 	rotors;
	Plugboard			plugboard;
	KeySheet 			keysheet;
};

#endif