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
	int 			getCurrPos();
	void 			rotateRotor();
	void 			buildAlphabet(std::string);
	void 			printAlphabet();
	void 			getFileContents();
	int 			getRotations();
	void 			setStartPos(char);
	void 			lowerConvert(char&);
	int 			findLetterPos(char);
	char 			inverseLetter(int);
	char 			retrieveLetter(int);
	void			buildInverse();
	char 			convertPosToChar(int);
	void 			printInverse();
	void 			shiftAlphabet();
	void 			resetCheck(int&, int&);

	private:
	int			a;
	int 			curr_pos;
	int 			rotations;
	std::string 		file_path;
	std::string		rotor_value;
	std::string 		rotor_contents;
	std::array<char, 26>	alphabet;
	std::array<char, 26>	inverse_alphabet;
};

#endif
