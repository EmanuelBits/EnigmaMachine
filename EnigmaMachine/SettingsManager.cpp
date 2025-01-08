#include "SettingsManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

SettingsManager::SettingsManager(const std::string& settingsFilePath)
    : positionRotor1(1), positionRotor2(1), positionRotor3(1), rotorTypes({ 1, 2, 3 }) {

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

        // Parse the first value: keyboard path (e.g., input.txt)
        if (!std::getline(ss, keyboardPath, ',')) {
            std::cerr << "Error: Could not parse keyboard path." << std::endl;
            exit(EXIT_FAILURE);
        }

        // Parse plugboard pairs (e.g., AB, CD, EF, GH, IJ)
        std::string plugPairStr;
        for (int i = 0; i < 5; i++) {
            if (!std::getline(ss, plugPairStr, ',')) {
                std::cerr << "Error: Could not parse plugboard pair " << i + 1 << std::endl;
                exit(EXIT_FAILURE);
            }
            if (plugPairStr.size() != 2) {
                std::cerr << "Error: Invalid plugboard pair format: " << plugPairStr << std::endl;
                exit(EXIT_FAILURE);
            }
            char letter1 = plugPairStr[0];
            char letter2 = plugPairStr[1];
            plugboardPairs.push_back(Plug(letter1, letter2));
        }

        // Parse rotor types (e.g., 1, 2, 3)
        for (int i = 0; i < 3; i++) {
            if (!std::getline(ss, value, ',')) {
                std::cerr << "Error: Could not parse rotor type " << i + 1 << std::endl;
                exit(EXIT_FAILURE);
            }
            rotorTypes[i] = std::stoi(value);
        }

        // Parse initial rotor positions (e.g., 5, 12, 19)
        if (!std::getline(ss, value, ',')) {
            std::cerr << "Error: Could not parse position for rotor 1." << std::endl;
            exit(EXIT_FAILURE);
        }
        positionRotor1 = std::stoi(value);
        if (!std::getline(ss, value, ',')) {
            std::cerr << "Error: Could not parse position for rotor 2." << std::endl;
            exit(EXIT_FAILURE);
        }
        positionRotor2 = std::stoi(value);
        if (!std::getline(ss, value, ',')) {
            std::cerr << "Error: Could not parse position for rotor 3." << std::endl;
            exit(EXIT_FAILURE);
        }
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