#include "Headers/Enigma.hpp"

Enigma::Enigma()
{

	// Read in Keysheet first to initialize the Enigma
	std::cout << "Enter Keysheet date value: ";
	getline(std::cin, sheet_number);
	keysheet = KeySheet(sheet_number);

	// Verify KeySheet info
	keysheet.viewInfo();

	// Assign Rotor values
	buildRotors(keysheet.getRotors());
	rotors = RotorCollection(l_rotor, m_rotor, r_rotor);

	// Add start positions to Rotors
	addStartPos(rotors);

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
	l_rotor = Rotor(oss.str());
	oss.str(std::string());

	oss << rotors.at(1);
	m_rotor = Rotor(oss.str());
	oss.str(std::string());

	oss << rotors.at(2);
	r_rotor = Rotor(oss.str());
	oss.str(std::string());
}

void Enigma::viewRotors()
{
	std::cout << r1 << ", " << r2 << ", " << r3 << std::endl;
}

void Enigma::addStartPos(RotorCollection& rotors)
{
	for (int i = 0; i < rotors.numOfRotors(); i++)
	{
		rotors.accessRotor(i).setStartPos(keysheet.getAlphas().at(i));
	}

}