#include "InputReader.h"
#include <cctype>

InputReader::InputReader(const std::string& filePath) : filePath(filePath) {
    readMessageFromFile();
}

void InputReader::readMessageFromFile() {
    std::ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        char ch;
        while (inputFile.get(ch)) {
            if (std::isalpha(ch)) {
                message += std::toupper(ch);  // Convert to uppercase and append to message
            }
        }
        inputFile.close();

        if (message.empty()) {
            std::cerr << "\033[33mWarning: No valid letters found in the input file!\033[0m" << std::endl;
        }
    } else {
        std::cerr << "\033[31mError: Unable to open file " << filePath << "\033[0m" << std::endl;
    }
}

std::string InputReader::getMessage() const {
    return message;
}