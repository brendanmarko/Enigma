#include "Headers/KeySheet.hpp"

KeySheet::KeySheet(std::string keysheet_value)
{
	// Build file path for target file
	file_path = "KeySheets/sheet";
	file_path.append(keysheet_value);
	file_path.append(".txt");

	// Extract info
	getFileContents();

}

void KeySheet::getFileContents()
{

	int 					counter = 0;
	std::string 			line = "";
	std::ifstream 			target_file;

	target_file.open(file_path.c_str(), std::ios::out);

	if (target_file.is_open())
	{

		while (getline(target_file, line))
	    {

	    	if (counter == 0)
	    	{
	    		buildRotor(line);
	    	}

	    	else if (counter == 1)
	    	{
	    		buildAlpha(line);
	    	}

	    counter++;

	    }

    target_file.close();
	
	}

}

void KeySheet::buildRotor(std::string line)
{

	for (int i = 0; i < line.length(); i++)
	{
		rotor_order.push_back(line.at(i) - '0');
	}

}

void KeySheet::buildAlpha(std::string line)
{

	for (int i = 0; i < line.length(); i++)
	{
		start_chars.push_back(line.at(i));
	}

}

void KeySheet::viewInfo()
{

	for (int i = 0; i < rotor_order.size(); i++)
	{
		std::cout << rotor_order.at(i);
	}	

	std::cout << std::endl;

	for (int i = 0; i < start_chars.size(); i++)
	{
		std::cout << start_chars.at(i);
	}	

	std::cout << std::endl;

}

std::vector<int> KeySheet::getRotors()
{
	return rotor_order;
}

std::vector<char> KeySheet::getAlphas()
{
	return start_chars;
}