#include "Headers/Enigma.hpp"

Enigma::Enigma()
{
    // Checks for invalid sheet input
	while (1)
	{
        // Read in Keysheet first to initialize the Enigma
		std::cout << "Enter Keysheet date value (1-3): ";
		getline(std::cin, sheet_number);

		if (std::stoi(sheet_number)>=1 && std::stoi(sheet_number)<=3)
			break;

        std::cout << "Invalid value entered, try again." << std::endl;
	}

	keysheet = KeySheet(sheet_number);

	// Display KeySheet info for debug
	// keysheet.viewInfo();

	// Assign Rotor values
	buildRotors(keysheet.getRotors());
	rotors = RotorCollection(l_rotor, m_rotor, r_rotor);

	// Add start positions to Rotors
	addStartPos(rotors);

	// Set the Plugboard settings
	plugboard = Plugboard(keysheet.getPlugboard());
	rotors.setPlugboard(plugboard);

	// Enigma Initialized
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
	for (int i=0; i<rotors.numOfRotors(); i++)
	{
		rotors.accessRotor(i).setStartPos(keysheet.getAlphas().at(i));
	}

}
