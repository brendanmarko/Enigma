#include "Headers/Rotor.hpp"

Rotor::Rotor()
{
	// empty
}

Rotor::Rotor(std::string rotor_value)
: curr_pos(0), a(0), rotations(0)
{
	// Build file path for target file
	file_path = "Rotors/Rotor";
	file_path.append(rotor_value);
	file_path.append(".txt");

	// Access target file and write to string
	getFileContents();
	buildAlphabet(rotor_contents);
	buildInverse();

	/*
	// Output Rotor info for debug
	std::cout << "New Rotor created from [" << file_path << "] : ";
	printAlphabet();
	*/
}

int Rotor::getCurrPos()
{
	return curr_pos;
}

void Rotor::buildAlphabet(std::string permutation)
{
	for (int i=0; i<26; i++)
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
	std::string 	line = "";
	std::ifstream 	target_file;

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
	a=(int) c;

	if (a>=65 && a<=90)
	{
		c=tolower(c);
	}

}

void Rotor::shiftAlphabet()
{	
	char c=alphabet[0];

	for (int i=0; i<alphabet.size()-1; i++)
	{
		alphabet[i]=alphabet[i+1];
	}

	alphabet[alphabet.size()-1] = c;
}

int Rotor::findLetterPos(char c)
{
	return (int) c-97;
}

char Rotor::retrieveLetter(int i)
{
	return alphabet[i];
}

char Rotor::inverseLetter(int i)
{
	return inverse_alphabet[i];
}

// convertPosToChar
// This function takes a position from alphabet and converts it into the appropriate char
char Rotor::convertPosToChar(int i)
{
	return (char) (i+97);
}

// buildInverse()
// This functions builds an inverse of the alphabet array for the flipped iterations
void Rotor::buildInverse()
{
	for (int i=0; i<alphabet.size(); i++)
	{
		inverse_alphabet[findLetterPos(retrieveLetter(i))] = convertPosToChar(i);
	}

}

void Rotor::printInverse()
{
	for (int i=0; i<inverse_alphabet.size(); i++)
	{
		std::cout << inverse_alphabet.at(i);
	}

	std::cout << std::endl;
}

// resetCheck(int, int)
// This function keeps the position and rotation values within bounds
void Rotor::resetCheck(int& r, int& p)
{
	if (p>25)
		p = 0;

	if (r>26)
		r = 0;

	return;
}

void Rotor::rotateRotor()
{
	curr_pos++;
	rotations++;
	resetCheck(rotations, curr_pos);
	shiftAlphabet();
	buildInverse();
}
