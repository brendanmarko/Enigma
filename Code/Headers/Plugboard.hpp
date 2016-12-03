#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <array>
#include <string>
#include <iostream>

class Plugboard
{
	public:
	Plugboard();
	Plugboard(std::string);

	public:
	void 					checkPlugboard(char&);
	void					printPlugboard();

	private:
	std::array<char, 26> 	plugboard;
	std::string 			temp;
};

#endif
