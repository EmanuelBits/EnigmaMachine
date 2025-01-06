#include "InputReader.h"
#include <cctype>

InputReader::InputReader(const std::string& filePath) : inputFile(filePath) {}

char InputReader::getNextCharacter() {
    char ch;
    while (inputFile.get(ch)) {
        if (std::isalpha(ch)) {
            return std::toupper(ch);
        }
    }
    return '\0';  // End of file or no valid characters
}

bool InputReader::hasMoreCharacters() const {
    return inputFile.peek() != EOF;
}