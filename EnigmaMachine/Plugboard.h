#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <vector>
#include "Plug.h"

class Plugboard {
public:
    // Constructor that takes 5 Plug objects as parameters
    Plugboard(const Plug& plug1, const Plug& plug2, const Plug& plug3, const Plug& plug4, const Plug& plug5);

    // Method to encode a character based on the plugboard settings
    char encode(char input);

private:
    // Vector representing the modified alphabet after applying plug swaps
    std::vector<char> alphabet;

    // Method to swap two characters in the alphabet based on a plug
    void applyPlug(const Plug& plug);
};

#endif // PLUGBOARD_H