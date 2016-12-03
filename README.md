# Enigma
This is an implementation of the encryption device used by German forces in WW2, the Enigma machine. This implementation serves as a simulation of the 3-Rotor model with a static reflector used.

The program runs by asking the user for a date value to input to simulate picking the proper day off a Keysheet chart as per actual use. This loads up a specific Keysheet combination that will construct the Rotors, placing them into proper order and starting positions as defined by the Keysheet entry. 

If you encrypt the message with one Keysheet and attempt to decrpyt it using a different Keysheet entry the message will not decode properly!