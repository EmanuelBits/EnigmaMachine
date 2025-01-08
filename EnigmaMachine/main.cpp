#include <iostream>
#include "EnigmaMachine.h"
#include "SettingsManager.h"
#include "EnigmaDescription.h"

int main() {
    EnigmaDescription::printInfo();

    // File path to the settings file
    std::string settingsFilePath = "settings.txt";

    //// Load the settings from the file using SettingsManager
    //SettingsManager settingsManager(settingsFilePath);

    

    //// Retrieve the settings
    //std::string inputFilePath = settingsManager.getKeyboardPath();
    //std::array<signed char, 3> rotorTypes = settingsManager.getRotorTypes();
    //int positionRotor1 = settingsManager.getPositionRotor1();
    //int positionRotor2 = settingsManager.getPositionRotor2();
    //int positionRotor3 = settingsManager.getPositionRotor3();

    std::string inputFilePath = "input.txt";
    InputReader inputReader(inputFilePath);

    std::array<signed char, 3> rotorTypes = { 1, 2, 3 };
    int positionRotor1 = 5;
    int positionRotor2 = 12;
    int positionRotor3 = 19;
    Plugboard plugboard(Plug('A', 'B'), Plug('C', 'D'), Plug('E', 'F'), Plug('G', 'H'), Plug('I', 'J'));

    Keyboard keyboard(inputReader);

    //// Retrieve the plugboard pairs (as a vector of Plug objects)
    //std::vector<Plug> plugboardPairs = settingsManager.getPlugboardPairs();

    //// Set up the plugboard with the retrieved plug pairs
    //Plugboard plugboard(plugboardPairs[0], plugboardPairs[1], plugboardPairs[2], plugboardPairs[3], plugboardPairs[3]);

    // Initialize the two Enigma Machines (one for encoding and one for decoding)
    EnigmaMachine encodingMachine(keyboard, plugboard, rotorTypes, positionRotor1, positionRotor2, positionRotor3);
    EnigmaMachine decodingMachine(keyboard, plugboard, rotorTypes, positionRotor1, positionRotor2, positionRotor3);

    // Set up the Enigma Machine for encoding and decoding messages
    std::cout << "Encoding message..." << std::endl;
    encodingMachine.start();  // Start encoding

    std::cout << "\nDecoding message..." << std::endl;
    decodingMachine.start();  // Start decoding (using the same settings)

    return 0;
}