#include "Keyboard.h"
#include <iostream>

Keyboard::Keyboard(const InputReader& inputReader) : message(inputReader.getMessage()), currentIndex(0) {
    if (message.empty()) {
        std::cerr << "Error: The input message is empty!" << std::endl;
        exit(EXIT_FAILURE);  // Exit if no message is found
    }
}

char Keyboard::getNextCharacter() {
    if (currentIndex < message.size()) {
        return message[currentIndex++];  // Return the current character and increment the index
    } else {
        return '\0';  // Return null character when end of message is reached
    }
}

void Keyboard::resetCurrentIndex() {
    currentIndex = 0;
}