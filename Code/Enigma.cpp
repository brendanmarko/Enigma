#include "Headers/Enigma.hpp"

Enigma::Enigma()
{

	// Read in Keysheet first to initialize the Enigma
	std::cout << "Enter Keysheet date value: ";
	getline(std::cin, sheet_number);
	KeySheet keysheet = KeySheet(sheet_number);

	// Verify KeySheet info
	keysheet.viewInfo();

	// Assign Rotor values
	buildRotors(keysheet.getRotors());

	// Build Rotors
	Rotor l_rotor = Rotor(r1);
	Rotor m_rotor = Rotor(r2);
	Rotor r_rotor = Rotor(r3);

	RotorCollection rotors = RotorCollection(l_rotor, m_rotor, r_rotor);

	// Enigma Initialized
	std::cout << "Enigma ready for use!" << std::endl;	

	// Get user input
	getline(std::cin, plaintext);

	// Handle user input

}

void Enigma::buildRotors(std::vector<int> rotors)
{

	std::ostringstream oss;

	oss << rotors.at(0);
	r1 = oss.str();
	oss.str(std::string());

	oss << rotors.at(1);
	r2 = oss.str();
	oss.str(std::string());

	oss << rotors.at(2);
	r3 = oss.str();
	oss.str(std::string());

}

void Enigma::viewRotors()
{
	std::cout << r1 << ", " << r2 << ", " << r3 << std::endl;
}