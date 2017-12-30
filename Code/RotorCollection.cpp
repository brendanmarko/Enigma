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
		r.printInverse();
		std::cout << "----------" << std::endl;
	}
}

Rotor& RotorCollection::accessRotor(int i)
{
	return rotors.at(i);
}

void RotorCollection::handleInput(std::string input)
{
	c=' ';

	for (int i=0; i<input.length(); i++)
	{	
		c=tolower(input.at(i));

		if (!specialChar(c))
		{
			plugboard.checkPlugboard(c);
			normalIteration(c);
			reflectorScramble(c);
			reverseIteration(c);
			rotorHandler();
			plugboard.checkPlugboard(c);
		}
		
		result += c;

	}

	std::cout << "Output: " << result << std::endl;

}

// normalIteration(char&)
// This function passes in a character that searches for its mapping on the alphabet arrays in each Rotor
// Note: These iteration runs numOfRotors()-1 -> 0
void RotorCollection::normalIteration(char& c)
{

	for (int i=numOfRotors()-1; i>=0; i--)
	{
		c=rotors.at(i).retrieveLetter(rotors.at(i).findLetterPos(c));
	}

}

// reflectorScramble(char&)
// This functions looks up the specified Reflector given in the RotorCollection ctor and reflects the paired value of c
void RotorCollection::reflectorScramble(char& c)
{
	reflector.setReflectorLetter(c);
}

// reverseIteration(char&)
// This function passes in a character that searches for its mapping on the inverted_alphabet arrays in each Rotor
// Note: These iteration runs 0 -> numOfRotors()-1
void RotorCollection::reverseIteration(char& c)
{
	for (int i=0; i<numOfRotors(); i++)
	{
		c=rotors.at(i).inverseLetter(rotors.at(i).findLetterPos(c));
	}

}

// rotorHandler()
// This function oversees the rotating of each of the rotors in which left side rotors depend on right side rotors
void RotorCollection::rotorHandler()
{
	rotors.at(2).rotateRotor();

	if (rotors.at(2).getRotations() == 26)
	{
		rotors.at(1).rotateRotor();

		if (rotors.at(1).getRotations() == 26)
			rotors.at(0).rotateRotor();
	}

}

// specialChar(char&)
// This simple helper function checks if input is a special entry in the special_texts[] in RotorCollection
bool RotorCollection::specialChar(char& c)
{

	for (int i=0; i<special_texts.size(); i++)
	{

		if (c == special_texts[i])
			return true;
	}

	return false;
}

void RotorCollection::setPlugboard(Plugboard& new_plugboard)
{
	plugboard=new_plugboard;
}
