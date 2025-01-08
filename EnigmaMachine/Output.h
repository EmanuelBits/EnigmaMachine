#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

class Output {
public:
    Output();  // Constructor to initialize the output message

    // Method to return the entire encrypted message
    std::string getEncodedMessage() const;

    // Method to add a letter to the encrypted message
    void addEncodedLetter(char letter);

private:
    std::string encodedMessage;  // Stores the entire encrypted message
};

#endif // OUTPUT_H