#include "Output.h"

Output::Output() : encodedMessage("") {}

std::string Output::getEncodedMessage() const {
    return encodedMessage;
}

void Output::addEncodedLetter(char letter) {
    encodedMessage += letter;
}