#include "Rotor.h"

Rotor::Rotor(signed char rotorType, int notchPosition) : position(0), atNotch(false), Type(0), notchPosition(26) {
    Type = rotorType;
    wiring = RotorEncoding::getRotorEncoding(rotorType);
    this->notchPosition = notchPosition;
}

char Rotor::encode(char input) {
    int index = (input - 'A' + position) % 26;  // Convert input to index
    return wiring[index];
}

char Rotor::encodeInReverseDirection(char input) {
    int index = (input - 'A' - position + 26) % 26; // Adjust position backward
    for (size_t i = 0; i < wiring.size(); ++i) {
        if (wiring[i] == (index + 'A')) {
            return (i - position + 26) % 26 + 'A';
        }
    }
    return NULL;
}

void Rotor::rotate() {
    position = (position + 1) % 26;
    atNotch = position == notchPosition;
}

bool Rotor::isAtNotch() const {
    return atNotch;
}

void Rotor::setPosition(int position) {
    this->position = position;
}

void Rotor::reset() {
    position = 0;
    atNotch = false;
}