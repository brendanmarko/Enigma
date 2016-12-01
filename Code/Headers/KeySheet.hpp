#ifndef KEYSHEET_HPP
#define KEYSHEET_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "stdlib.h"

class KeySheet
{
	public:
	KeySheet();
	KeySheet(std::string);

	public:
	void 					buildRotor(std::string);
	void 					buildAlpha(std::string);
	void 					getFileContents();
	void 					viewInfo();
	std::vector<int> 		getRotors();
	std::vector<char> 		getAlphas();	

	private:
	std::vector<int>		rotor_order;
	std::vector<char>		start_chars;
	std::string 			file_path;
};

#endif