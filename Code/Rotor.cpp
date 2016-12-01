#include "Headers/Rotor.hpp"

Rotor::Rotor(std::string rotor_value)
{

	// Build file path for target file
	file_path = "Rotors/Rotor";
	file_path.append(rotor_value);
	file_path.append(".txt");

	// Access target file and write to string
	getFileContents();
	buildAlphabet(rotor_contents);

	std::cout << "New Rotor created from [" << file_path << "] @ ";
	printAlphabet();

}

int Rotor::getStartPos()
{
	return start_pos;
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