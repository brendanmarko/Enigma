#include "Headers/Enigma.hpp"

Enigma::Enigma()
{

	// Read in Keysheet first to initialize the Enigma
	

	// Build Rotors
	Rotor l_rotor = Rotor("1");
	Rotor m_rotor = Rotor("2");
	Rotor r_rotor = Rotor("3");

	RotorCollection rotors = RotorCollection(l_rotor, m_rotor, r_rotor);

	// Enigma Initialized
	std::cout << "Enigma ready for use!" << std::endl;	

}