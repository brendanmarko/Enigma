#include "Headers/Plugboard.hpp"

Plugboard::Plugboard()
{
	// empty
}

Plugboard::Plugboard(std::vector<std::pair<char, char>> board)
{
	letter_swaps=board;
}

// checkPlugboard(char&)
// This function checks to see if a character has to be swapped passing through the Plugboard
void Plugboard::checkPlugboard(char& c)
{
	for (int i=0; i<letter_swaps.size(); i++)
	{

		if (c == letter_swaps.at(i).first)
			c = letter_swaps.at(i).second;

		else if (c == letter_swaps.at(i).second)
			c = letter_swaps.at(i).first;
	}
}
