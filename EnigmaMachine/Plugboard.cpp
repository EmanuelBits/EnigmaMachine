#include "Plugboard.h"

// Constructor that initializes the plugboard with 5 plugs
Plugboard::Plugboard(const Plug& plug1, const Plug& plug2, const Plug& plug3, const Plug& plug4, const Plug& plug5) {
    // Initialize the alphabet with A-Z
    alphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    // Apply each plug to the alphabet
    applyPlug(plug1);
    applyPlug(plug2);
    applyPlug(plug3);
    applyPlug(plug4);
    applyPlug(plug5);
}

// Method to apply a plug swap to the alphabet
void Plugboard::applyPlug(const Plug& plug) {
    char firstLetter = plug.getLetter1();
    char secondLetter = plug.getLetter2();

    // Find the indices of the letters to swap
    int index1 = firstLetter - 'A';
    int index2 = secondLetter - 'A';

    // Swap the letters in the alphabet
    std::swap(alphabet[index1], alphabet[index2]);
}

// Method to encode a character using the plugboard
char Plugboard::encode(char input) {
    int index = input - 'A';  // Convert input character to index
    return alphabet[index];   // Return the swapped character from the alphabet
}