#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <string>
#include <fstream>
#include <iostream>

class Rotor 
{
	public:
	Rotor();
	Rotor(std::string);

	public:
	int 				getCurrPos();
	void 				buildAlphabet(std::string);
	void 				printAlphabet();
	void 				getFileContents();
	int 				getRotations();
	void 				setStartPos(char);
	void 				lowerConvert(char&);

	private:
	int					a;
	int 				curr_pos;
	char 				alphabet[26];
	int 				rotations;
	std::string 		file_path;
	std::string			rotor_value;
	std::string 		rotor_contents;
};

#endif