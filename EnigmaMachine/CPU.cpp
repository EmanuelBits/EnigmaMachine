#include "CPU.h"

CPU::CPU() {
    // Initialize components
}

char CPU::processCharacter(char input) {
    // Send input through Plugboard
    char processed = plugboard.swap(input);

    // Pass through rotors forward
    for (int i = 0; i < 3; i++) {
        processed = rotors[i].encode(processed);
    }

    // Reflector
    processed = reflector.reflect(processed);

    // Pass back through rotors in reverse
    for (int i = 2; i >= 0; i--) {
        processed = rotors[i].decode(processed);
    }

    // Send back through Plugboard
    processed = plugboard.swap(processed);

    // Rotate rotors
    rotateFirstRotor();

    return processed;
}

void CPU::rotateFirstRotor() {
    // Rotate first rotor and handle cascading rotations
    rotors[0].rotate();
    if (rotors[0].isAtNotch()) {
        rotors[1].rotate();
        if (rotors[1].isAtNotch()) {
            rotors[2].rotate();
        }
    }
}