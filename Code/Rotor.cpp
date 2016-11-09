#include "Headers/Rotor.hpp"

Rotor::Rotor()
{
	std::cout << "New Rotor created." << std::endl;
}

std::string Rotor::getName()
{
	return name;
}