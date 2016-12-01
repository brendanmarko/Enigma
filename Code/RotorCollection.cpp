#include "Headers/RotorCollection.hpp"

RotorCollection::RotorCollection()
{
	// empty
}

RotorCollection::RotorCollection(Rotor& r1, Rotor& r2, Rotor& r3)
: num_rotors(0)
{
	addRotor(r1);
	addRotor(r2);
	addRotor(r3);
	reflector = Reflector("1");
}

int RotorCollection::numOfRotors()
{
	return num_rotors;
}

void RotorCollection::addRotor(Rotor& curr_rotor)
{
	rotors.push_back(curr_rotor);
	num_rotors++;
}

void RotorCollection::viewAlphabets()
{
	for (Rotor r : rotors)
	{
		r.printAlphabet();
	}

}

Rotor& RotorCollection::accessRotor(int i)
{
	return rotors.at(i);
}

void RotorCollection::handleInput(std::string input)
{

	c = ' ';
	std::cout << "Passed input: " << input << std::endl;

	for (int i = 0; i < input.length(); i++)
	{
		c = input.at(i);
		normalIteration(c);
		std::cout << "c: " << c << std::endl;
		reflectorScramble(c);
		std::cout << "c: " << c << std::endl;
		reverseIteration(c);
	}

}

void RotorCollection::normalIteration(char& c)
{
	int temp = 0;

	for (Rotor r : rotors)
	{
		temp = r.findLetterPos(c);
		c = r.retrieveLetter(temp);
	}

}

void RotorCollection::reflectorScramble(char& c)
{
	reflector.setReflectorLetter(c);
}

void reverseIteration(char& c)
{
	
}