#ifndef ROTORENCODING_H
#define ROTORENCODING_H

#include <vector>

class RotorEncoding {
public:
    static std::vector<char> getRotorEncoding(signed char rotorType); // Returns encoding for a given rotor type

private:
    static std::vector<std::vector<char>> rotorEncodings; // Holds all 5 rotor types
};

#endif // ROTORENCODING_H