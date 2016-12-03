#ifndef KEYSHEET_HPP
#define KEYSHEET_HPP

#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <iostream>

class KeySheet
{
	public:
	KeySheet();
	KeySheet(std::string);

	public:
	void 						buildRotor(std::string);
	void 						buildAlpha(std::string);
	void 						buildPlugboard(std::string);
	void 						getFileContents();
	void 						viewInfo();
	std::vector<int> 				getRotors();
	std::vector<char> 				getAlphas();	
	std::vector<std::pair<char, char>>		getPlugboard();

	private:
	std::vector<int>				rotor_order;
	std::vector<char>				start_chars;
	std::vector<std::pair<char, char>>		plugboard_swaps;
	std::string 					file_path;
};

#endif
