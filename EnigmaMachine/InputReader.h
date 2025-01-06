#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <string>
#include <fstream>

class InputReader {
public:
    InputReader(const std::string& filePath);
    char getNextCharacter();
    bool hasMoreCharacters() const;

private:
    std::ifstream inputFile;
};

#endif // INPUTREADER_H