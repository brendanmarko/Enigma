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
	std::cout << "Result: ";

	for (int i = 0; i < input.length(); i++)
	{
		c = input.at(i);
		normalIteration(c);
		reflectorScramble(c);
		reverseIteration(c);
		std::cout << c;
		rotorHandler();
	}

	std::cout << std::endl;

}

void RotorCollection::normalIteration(char& c)
{
	for (Rotor r : rotors)
	{
		c = r.retrieveLetter(r.findLetterPos(c));
	}

}

void RotorCollection::reflectorScramble(char& c)
{
	reflector.setReflectorLetter(c);
}

void RotorCollection::reverseIteration(char& c)
{
	for (int i = numOfRotors()-1; i >= 0; i--)
	{
		c = rotors.at(i).retrieveLetter(rotors.at(i).findLetterPos(c));
	}

}

void RotorCollection::rotorHandler()
{
	// std::cout << "Rotating r_right" << std::endl;
	rotors.at(numOfRotors()-1).rotateRotor();

	if (rotors.at(numOfRotors()-1).getRotations() == 26)
	{
		// std::cout << "	Rotating r_middle" << std::endl;
		rotors.at(numOfRotors()-2).rotateRotor();

		if (rotors.at(numOfRotors()-2).getRotations() == 26)
		{
			// std::cout << "		Rotating r_left" << std::endl;
			rotors.at(numOfRotors()-3).rotateRotor();
		}

	}

}