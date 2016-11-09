#include "Headers/Enigma.hpp"

Enigma::Enigma()
{
	std::cout << "Engima created." << std::endl;
}

void Enigma::addRotor(Rotor &curr_rotor)
{
	std::cout << "Rotor added with name " << curr_rotor.getName() << std::endl;
}