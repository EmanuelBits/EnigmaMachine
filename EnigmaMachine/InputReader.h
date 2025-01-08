#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <string>
#include <iostream>
#include <fstream>

class InputReader {
public:
    explicit InputReader(const std::string& filePath);

    // Method to return the entire message read from the file
    std::string getMessage() const;

private:
    std::string filePath;
    std::string message;

    void readMessageFromFile();
};

#endif // INPUTREADER_H