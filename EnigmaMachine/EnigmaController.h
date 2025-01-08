#ifndef ENIGMACONTROLLER_H
#define ENIGMACONTROLLER_H

#include <vector>
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "Keyboard.h"
#include "Output.h"

class EnigmaController {
public:
    EnigmaController(Keyboard& keyboard, Plugboard& plugboard, Reflector& reflector, std::vector<Rotor>& rotors, Output& output);
    void encode();  // Start encoding the message

private:
    Keyboard& keyboard;
    Plugboard& plugboard;
    Reflector& reflector;
    std::vector<Rotor>& rotors;
    Output& output;

    char processCharacter(char input);  // Handles the flow through the machine components
};

#endif // ENIGMACONTROLLER_H