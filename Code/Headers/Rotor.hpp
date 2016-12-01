#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <string>
#include <fstream>
#include <iostream>

class Rotor 
{

	public:
	Rotor(std::string);
	int 				getStartPos();
	void 				buildAlphabet(std::string);
	void 				printAlphabet();
	void 				getFileContents();
	int 				getRotations();

	private:
	int 				start_pos;
	std::string 		rotor_contents;
	char 				alphabet[26];
	std::string 		file_path;
	std::string			rotor_value;
	int 				rotations;

};

#endif