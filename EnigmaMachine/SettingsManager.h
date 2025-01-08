#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <string>
#include <vector>
#include <array>
#include <utility>
#include "Plug.h"

class SettingsManager {
private:
    std::string keyboardPath;
    std::array<signed char, 3> rotorTypes;
    int positionRotor1;
    int positionRotor2;
    int positionRotor3;
    std::vector<Plug> plugboardPairs;

public:
    // Constructor that reads settings from a file
    SettingsManager(const std::string& settingsFilePath);

    // Getters
    std::string getKeyboardPath() const;
    std::array<signed char, 3> getRotorTypes() const;
    int getPositionRotor1() const;
    int getPositionRotor2() const;
    int getPositionRotor3() const;
    std::vector<Plug> getPlugboardPairs() const;
};

#endif // SETTINGSMANAGER_H