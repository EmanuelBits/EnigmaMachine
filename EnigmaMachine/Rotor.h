#ifndef ROTOR_H
#define ROTOR_H

#include <vector>
#include <iostream>
#include "RotorEncoding.h"

class Rotor {
public:
    Rotor(signed char rotorType, int notchPosition);  // Constructor takes rotor type to get encoding
    char encode(char input);  // Encodes a character through the rotor
    char encodeInReverseDirection(char input);  // Decodes a character through the rotor
    void rotate();  // Rotates the rotor by one position
    bool isAtNotch() const;  // Checks if the rotor is at the notch position
    void setPosition(int position);
    void reset();  // Resets the rotor to its initial position

private:
    signed char Type;
    std::vector<char> wiring;  // The rotor's wiring/encoding
    int position;  // The current position of the rotor
    int notchPosition;  // The notch position, used to decide when the next rotor increments
    bool atNotch;  // If the rotor is at its notch
};

#endif // ROTOR_H