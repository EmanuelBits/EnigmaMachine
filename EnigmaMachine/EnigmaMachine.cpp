#include "EnigmaMachine.h"

EnigmaMachine::EnigmaMachine(Keyboard keyboard, Plugboard plugboard, std::array<signed char, 3> rotorsType, int positionRotor1, int positionRotor2, int positionRotor3)
    : keyboard(keyboard),
    plugboard(plugboard),
    reflector(),
    rotorType1(1, 20),
    rotorType2(2, 21),
    rotorType3(3, 22),
    rotorType4(4, 23),
    rotorType5(5, 24),
    output(),
    controller(this->keyboard, this->plugboard, this->reflector, this->rotors, this->output) {

    // Clear any existing rotors and add the specified ones
    rotors.clear();

    for (size_t i = 0; i < rotorsType.size(); i++) {
        switch (rotorsType[i]) {
        case 1:
            rotors.push_back(rotorType1);
            break;
        case 2:
            rotors.push_back(rotorType2);
            break;
        case 3:
            rotors.push_back(rotorType3);
            break;
        case 4:
            rotors.push_back(rotorType4);
            break;
        case 5:
            rotors.push_back(rotorType5);
            break;
        default:
            std::cerr << "Invalid rotor type: " << static_cast<int>(rotorsType[i]) << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    // Set the initial positions of the rotors
    if (rotors.size() >= 3) {
        rotors[0].setPosition(positionRotor1);
        rotors[1].setPosition(positionRotor2);
        rotors[2].setPosition(positionRotor3);
    } else {
        std::cerr << "Insufficient rotors initialized." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void EnigmaMachine::start() {
    controller.encode();
    std::cout << "Encoded message: " << output.getEncodedMessage() << std::endl;
}