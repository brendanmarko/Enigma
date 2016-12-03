#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <array>
#include <string>
#include <vector>
#include <iostream>

class Plugboard
{
	public:
	Plugboard();
	Plugboard(std::vector<std::pair<char, char>>);

	public:
	void 									checkPlugboard(char&);
	void									printPlugboard();

	private:
	std::vector<std::pair<char, char>> 		letter_swaps;
};

#endif
