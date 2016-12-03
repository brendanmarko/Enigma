#include "Headers/Plugboard.hpp"

Plugboard::Plugboard()
{
	plugboard = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	temp = " ";
}

Plugboard::Plugboard(std::string s)
{
	printPlugboard();
	std::cout << "Before splitting string: " << s << std::endl;

}

// checkPlugboard(char&)
// This function checks to see if a character has to be swapped passing through the Plugboard
void Plugboard::checkPlugboard(char& c)
{



}

void Plugboard::printPlugboard()
{
	for (int i = 0; i < plugboard.size(); i++)
	{
		std::cout << plugboard[i];
	}

	std::cout << std::endl;
}