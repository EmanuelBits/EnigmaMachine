#include "EnigmaDescription.h"

void EnigmaDescription::printInfo() {
    printTitle();
    printDescription();
    printDrawing();
}

void EnigmaDescription::printTitle() {
    setConsoleColor("\033[1;34m"); // Bold Blue
    std::cout << "\n=============================\n";
    std::cout << "        ENIGMA MACHINE       \n";
    std::cout << "=============================\n";
    resetConsoleColor();
}

void EnigmaDescription::printDescription() {
    setConsoleColor("\033[1;33m"); // Bold Yellow
    std::cout << "\nAbout the Project:\n";
    std::cout << "This project simulates an 8-bit Enigma Machine capable of encoding\n";
    std::cout << "and decoding text using low-level bit manipulation techniques.\n";
    std::cout << "The program demonstrates the fundamentals of cryptography and\n";
    std::cout << "low-level CPU-like behavior.\n";
    resetConsoleColor();
}

void EnigmaDescription::printDrawing() {
    setConsoleColor("\033[1;32m"); // Bold Green
    std::cout << "\n[ 8-bit CPU Representation ]\n";
    std::cout << "      +===================+\n";
    std::cout << "      |  8-BIT CPU CORE   |\n";
    std::cout << "  +---+===================+---+\n";
    std::cout << "  |         CONTROL UNIT       |\n";
    std::cout << "+---+-----------------------+---+\n";
    std::cout << "| R |   Arithmetic Logic    | PC |\n";
    std::cout << "| E |       Unit (ALU)      | R  |\n";
    std::cout << "| G |-----------------------| G  |\n";
    std::cout << "|   |   Registers & Memory  |    |\n";
    std::cout << "+---+-----------------------+---+\n";
    std::cout << "      |    DATA BUS         |\n";
    std::cout << "      +---------------------+\n";
    resetConsoleColor();
}

void EnigmaDescription::setConsoleColor(const std::string& color) {
    std::cout << color;
}

void EnigmaDescription::resetConsoleColor() {
    std::cout << "\033[0m"; // Reset color
}