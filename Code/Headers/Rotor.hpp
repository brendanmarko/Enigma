#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <array>
#include <string>
#include <fstream>
#include <iostream>

class Rotor 
{
	public:
	Rotor();
	Rotor(std::string);

	public:
	int 					getCurrPos();
	void 					rotateRotor();
	void 					buildAlphabet(std::string);
	void 					printAlphabet();
	void 					getFileContents();
	int 					getRotations();
	void 					setStartPos(char);
	void 					lowerConvert(char&);
	int 					findLetterPos(char);
	char 					retrieveLetter(int);

	private:
	int						a;
	int 					curr_pos;
	std::array<char, 26>	alphabet;
	int 					rotations;
	std::string 			file_path;
	std::string				rotor_value;
	std::string 			rotor_contents;
};

#endif