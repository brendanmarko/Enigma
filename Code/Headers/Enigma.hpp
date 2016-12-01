#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include <vector>
#include <sstream>
#include <iostream>
#include "Rotor.hpp"
#include "KeySheet.hpp"
#include "RotorCollection.hpp"

class Enigma
{

	public:
	Enigma();

	public:
	void 				buildRotors(std::vector<int>);
	void 				addStartPos(RotorCollection&);
	void 				viewRotors();

	private:
	std::string 		plaintext;
	std::string 		output_file;
	std::string 		sheet_number;
	std::string			r1, r2, r3;
	Rotor 				l_rotor, m_rotor, r_rotor;
	RotorCollection 	rotors;
	KeySheet 			keysheet;

};

#endif