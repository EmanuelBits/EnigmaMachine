#ifndef ENIGMA_DESCRIPTION_H
#define ENIGMA_DESCRIPTION_H

#include <iostream>
#include <string>

class EnigmaDescription {
public:
    // Public method to print the project information
    static void printInfo();

private:
    // Private methods to organize the output
    static void printTitle();
    static void printDescription();
    static void printDrawing();
    static void setConsoleColor(const std::string& color);
    static void resetConsoleColor();
};

#endif // ENIGMA_DESCRIPTION_H