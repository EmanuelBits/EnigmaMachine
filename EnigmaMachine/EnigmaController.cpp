#include "EnigmaController.h"
#include <iostream>

EnigmaController::EnigmaController(Keyboard& keyboard, Plugboard& plugboard, Reflector& reflector, std::vector<Rotor>& rotors, Output& output)
    : keyboard(keyboard), plugboard(plugboard), reflector(reflector), rotors(rotors), output(output) {
}

void EnigmaController::encode() {
    char inputChar;
    while ((inputChar = keyboard.getNextCharacter()) != '\0') {
        char encodedChar = processCharacter(inputChar);
        output.addEncodedLetter(encodedChar);
    }
}

char EnigmaController::processCharacter(char input) {
    // Step 1: Rotate the first rotor (and cascade if necessary)
    rotors[0].rotate();
    if (rotors[0].isAtNotch()) {
        rotors[1].rotate();
        if (rotors[1].isAtNotch()) {
            rotors[2].rotate();
        }
    }

    // Step 2: Pass through Plugboard
    char pluggedChar = plugboard.encode(input);

    // Step 3: Pass through Rotors (Forward direction)
    for (auto& rotor : rotors) {
        pluggedChar = rotor.encode(pluggedChar);
    }

    // Step 4: Pass through Reflector
    char reflectedChar = reflector.encode(pluggedChar);

    // Step 5: Pass back through Rotors (Reverse direction)
    for (auto it = rotors.rbegin(); it != rotors.rend(); ++it) {
        reflectedChar = it->encodeInReverseDirection(reflectedChar);
    }

    // Step 6: Pass through Plugboard again
    char outputChar = plugboard.encode(reflectedChar);

    return outputChar;
}