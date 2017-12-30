#include "Headers/KeySheet.hpp"

KeySheet::KeySheet()
{
  // empty
}

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
  int             counter = 0;
  std::string     line = "";
  std::ifstream   target_file;

  target_file.open(file_path.c_str(), std::ios::out);

  if (target_file.is_open())
  {
    while (getline(target_file, line))
    {
      if (counter==0)
        buildRotor(line);

      else if (counter==1)
        buildAlpha(line);

      else if (counter==2)
        buildPlugboard(line);

      counter++;
    }

    target_file.close();
  }
}

void KeySheet::buildRotor(std::string line)
{
  for (int i=0; i<line.length(); i++)
  {
    rotor_order.push_back(line.at(i) - '0');
  }
}

void KeySheet::buildAlpha(std::string line)
{
  for (int i=0; i<line.length(); i++)
  {
    start_chars.push_back(line.at(i));
  }
}

//buildPlugboard(std::string)
// This function takes a line of input and generates pairs, using the space between the pairs as a tokenizer
void KeySheet::buildPlugboard(std::string line)
{

  int   i=0;
  int   x=0;
  char  c=' ';

  for (i=0; i<line.length(); i++)
  {

    if (line.at(i)==' ')
    {
      // do nothing
    }

    else if (x<1)
    {  
      c=tolower(line.at(i));
      x++;
    }

    else
    {
      plugboard_swaps.push_back(std::make_pair(c, tolower(line.at(i))));
      x=0;
    }
  }
}

void KeySheet::viewInfo()
{
  for (int i=0; i<rotor_order.size(); i++)
  {
    std::cout << rotor_order.at(i);
  }  

  std::cout << std::endl;

  for (int i=0; i<start_chars.size(); i++)
  {
    std::cout << start_chars.at(i);
  }  

  std::cout << std::endl;

  for (int i=0; i<plugboard_swaps.size(); i++)
  {
    std::cout << plugboard_swaps.at(i).first << plugboard_swaps.at(i).second << " ";
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

std::vector<std::pair<char, char>> KeySheet::getPlugboard()
{
  return plugboard_swaps;
}
