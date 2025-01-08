#ifndef ENIGMAMACHINE_H
#define ENIGMAMACHINE_H

#include <array>
#include <vector>
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "Keyboard.h"
#include "Output.h"
#include "EnigmaController.h"

class EnigmaMachine {
public:
    EnigmaMachine(Keyboard keyboard, Plugboard plugboard, std::array<signed char, 3> rotorsType, int positionRotor1, int positionRotor2, int positionRotor3);
    void start();  // Starts the Enigma Machine

private:
    Keyboard keyboard;
    Plugboard plugboard;
    Reflector reflector;
    Rotor rotorType1;
    Rotor rotorType2;
    Rotor rotorType3;
    Rotor rotorType4;
    Rotor rotorType5;
    std::vector<Rotor> rotors;
    Output output;
    EnigmaController controller;
};

#endif // ENIGMAMACHINE_H