#include "RotorEncoding.h"

std::vector<std::vector<char>> RotorEncoding::rotorEncodings = {
    // Rotor Type 1
    {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'},

    // Rotor Type 2
    {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'},

    // Rotor Type 3
    {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'},

    // Rotor Type 4
    {'N', 'T', 'Z', 'W', 'E', 'X', 'L', 'J', 'B', 'G', 'V', 'Y', 'C', 'U', 'O', 'D', 'K', 'Q', 'S', 'I', 'R', 'F', 'A', 'M', 'H', 'P'},

    // Rotor Type 5
    {'I', 'R', 'T', 'Z', 'J', 'Q', 'P', 'A', 'U', 'V', 'K', 'N', 'S', 'D', 'F', 'X', 'W', 'L', 'O', 'H', 'Y', 'C', 'M', 'B', 'G', 'E'}
};

std::vector<char> RotorEncoding::getRotorEncoding(signed char rotorType) {
    if (rotorType >= 0 && rotorType < rotorEncodings.size()) {
        return rotorEncodings[rotorType];
    }
    return {};
}