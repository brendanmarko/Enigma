# Enigma
This is an implementation of the encryption device used by German forces in WW2, the Enigma machine. This implementation serves as a simulation of the 3-Rotor model with a static reflector used and a 6-pair Plugboard.

The program runs by asking the user for a date value to input to simulate picking the proper day off a Keysheet chart as per actual use. This loads up a specific Keysheet combination that will construct the Rotors, placing them into proper order and starting positions as defined by the Keysheet entry. 

If you encrypt the message with one Keysheet and attempt to decrpyt it using a different Keysheet entry the message will not decode properly!

# Makefile
There is a Makefile provided to ease compiling and running, the commands are as follows:
### make compile
	compiles the application
### make run
	runs the application
### make clean
	removes executable

# Folder Layout
This implementation uses text files to store values for Rotors, Reflectors and KeySheets. Each of the described type has a folder to store that type of input:
* Rotors are stored as "/Rotors/RotorX.txt"
* Reflectors similarly "/Reflectors/ReflectorX.txt"
* Lastly, Keysheets as "/KeySheets/sheetX.txt"

The KeySheet contains all the information needed to construct the layout of the machine with respect to the Rotors, Reflector and Plugboard settings.

# Note on Keysheets
### Creating new KeySheets, such as the one below, use the format given  
* 132
* ARK
* AB CD EX FU GR WM

### Format
* Rotor order consisting of permutations of {1, 2, 3} of size 3
* Rotor Start Positions per Rotor, Left to Right
* 6 Permutation pairs to be used on the PlugBoard to swap letters at input
	* Space used as a tokenizer for Plugboard initialization
