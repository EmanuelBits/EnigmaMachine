#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>
#include "InputReader.h"  // Include the InputReader class

class Keyboard {
public:
    Keyboard(const InputReader& inputReader);  // Constructor takes InputReader object
    char getNextCharacter();  // Method to return the next character in the message
    void resetCurrentIndex();

private:
    std::string message;  // Stores the message from InputReader
    size_t currentIndex;  // Keeps track of the current position in the message
};

#endif // KEYBOARD_H