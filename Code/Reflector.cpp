#include "Headers/Reflector.hpp"

Reflector::Reflector()
{

}

Reflector::Reflector(std::string reflector_num)
{
	// Build file path for target file
	file_path = "Reflectors/reflector";
	file_path.append(reflector_num);
	file_path.append(".txt");

	// Access target file and write to string
	getFileContents();
	buildAlphabet(reflector_contents);

}

void Reflector::getFileContents()
{
	std::string 			line = "";
	std::ifstream 			target_file;

	target_file.open(file_path.c_str(), std::ios::out);

	if (target_file.is_open())
	{

		while (getline(target_file, line))
	    {
	      reflector_contents = line;
	    }

	target_file.close();
	
	}

}

void Reflector::buildAlphabet(std::string permutation)
{
	for (int i = 0; i < 26; i++)
	{
		reflector_board[i] = permutation[i];
	}

}

void Reflector::viewReflector()
{
	for (int i = 0; i < reflector_board.size(); i++)
	{
		std::cout << reflector_board.at(i);
	}

	std::cout << std::endl;
}

void Reflector::setReflectorLetter(char& c)
{
	c = reflector_board[findLetterPos(c)];
}

int Reflector::findLetterPos(char& c)
{
	return (int) c - 97;
}