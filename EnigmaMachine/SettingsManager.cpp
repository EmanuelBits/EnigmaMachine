#include "SettingsManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

SettingsManager::SettingsManager(const std::string& settingsFilePath) {
    // Open the settings file
    std::ifstream settingsFile(settingsFilePath);
    if (!settingsFile.is_open()) {
        std::cerr << "Error: Could not open settings file." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Read the file line by line and parse the values
    std::string line;
    while (std::getline(settingsFile, line)) {
        std::istringstream ss(line);
        std::string value;

        // Parse the first line (keyboard path and plugboard pairs)
        std::getline(ss, keyboardPath, ',');

        // Parse plugboard pairs
        std::string plugPairStr;
        while (std::getline(ss, plugPairStr, ',')) {
            char letter1 = plugPairStr[0];
            char letter2 = plugPairStr[1];
            plugboardPairs.push_back(Plug(letter1, letter2));
        }

        // Parse rotor types
        std::getline(ss, value, ',');
        rotorTypes[0] = std::stoi(value);
        std::getline(ss, value, ',');
        rotorTypes[1] = std::stoi(value);
        std::getline(ss, value, ',');
        rotorTypes[2] = std::stoi(value, nullptr, 10);

        // Parse initial rotor positions
        std::getline(ss, value, ',');
        positionRotor1 = std::stoi(value);
        std::getline(ss, value, ',');
        positionRotor2 = std::stoi(value);
        std::getline(ss, value, ',');
        positionRotor3 = std::stoi(value);
    }

    // Close the settings file
    settingsFile.close();
}

std::vector<Plug> SettingsManager::getPlugboardPairs() const {
    return plugboardPairs;  // Return the vector of Plug objects
}

std::string SettingsManager::getKeyboardPath() const {
    return keyboardPath;
}

std::array<signed char, 3> SettingsManager::getRotorTypes() const {
    return rotorTypes;
}

int SettingsManager::getPositionRotor1() const {
    return positionRotor1;
}

int SettingsManager::getPositionRotor2() const {
    return positionRotor2;
}

int SettingsManager::getPositionRotor3() const {
    return positionRotor3;
}