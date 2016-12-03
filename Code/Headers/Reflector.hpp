#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include <array>
#include <string>
#include <fstream>
#include <iostream>

class Reflector 
{
	public:
	Reflector();
	Reflector(std::string);
	
	public:
	void 			viewReflector();
	void 			getFileContents();
	void 			buildAlphabet(std::string);
	void 			setReflectorLetter(char&);
	int			findLetterPos(char&);

	private:
	std::array<char, 26>	reflector_board;
	std::string		file_path;
	std::string 		reflector_contents;
};

#endif 
