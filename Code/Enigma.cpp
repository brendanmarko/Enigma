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

	// Set the Plugboard settings
	plugboard = Plugboard(keysheet.getPlugboard());
	rotors.setPlugboard(plugboard);

	// Enigma Initialized
	std::cout << "Enigma ready for use!" << std::endl;	
	std::cout << "Secret: ";

	// Get user input
	getline(std::cin, plaintext);

	// Handle user input
	rotors.handleInput(plaintext);
}

// buildRotors(std::vector)
// This function assigns the Rotors their designated alphabets according to the Rotor setup
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

// addStartPos(RotorCollection&)
// This function assigns starting positions to the Rotors based upon the KeySheet selected
void Enigma::addStartPos(RotorCollection& rotors)
{
	for (int i = 0; i < rotors.numOfRotors(); i++)
	{
		rotors.accessRotor(i).setStartPos(keysheet.getAlphas().at(i));
	}

}