#ifndef CPU_H
#define CPU_H

#include "ALU.h"
#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

class CPU {
public:
    CPU();
    char processCharacter(char input); // Process a character through Enigma components

private:
    ALU alu;
    Plugboard plugboard;
    Rotor rotors[3];
    Reflector reflector;
    void rotateFirstRotor();
};

#endif // CPU_H