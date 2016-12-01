#include "Headers/Rotor.hpp"

Rotor::Rotor()
{
	// empty
}

Rotor::Rotor(std::string rotor_value)
: curr_pos(0), a(0)
{
	// Build file path for target file
	file_path = "Rotors/Rotor";
	file_path.append(rotor_value);
	file_path.append(".txt");

	// Access target file and write to string
	getFileContents();
	buildAlphabet(rotor_contents);

	std::cout << "New Rotor created from [" << file_path << "] : ";
	printAlphabet();
}

int Rotor::getCurrPos()
{
	return curr_pos;
}

void Rotor::buildAlphabet(std::string permutation)
{
	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = permutation[i];
	}

}

void Rotor::printAlphabet()
{
	for (int i = 0; i < 26; i++)
	{
		std::cout << alphabet[i];
	}

	std::cout << std::endl;
}

void Rotor::getFileContents()
{
	std::string 			line = "";
	std::ifstream 			target_file;

	target_file.open(file_path.c_str(), std::ios::out);

	if (target_file.is_open())
	{

		while (getline(target_file, line))
	    {
	      rotor_contents = line;
	    }

	target_file.close();
	
	}

}

int Rotor::getRotations()
{
	return rotations;
}

// setStartPos(char)
// This function determines where the Rotor should set its start_pos based upon the character intake 
// ie) a=0, z=25
void Rotor::setStartPos(char c)
{
	lowerConvert(c);
	curr_pos = (int)c - 97;
}

// lowerConvert(char&)
// This function replaces passed char with lower-case conversion if needed
void Rotor::lowerConvert(char& c)
{
	a = (int) c;

	if (a >= 65 && a <= 90)
	{
		c = tolower(c);
	}

}

void Rotor::rotateRotor()
{
	curr_pos++;
	rotations++;
}

int Rotor::findLetterPos(char c)
{
	return (int) c - 97;
}

char Rotor::retrieveLetter(int i)
{
	return alphabet[i];
}