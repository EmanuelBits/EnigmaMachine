#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "CPU.h"
#include "InputReader.h"

class Keyboard {
public:
    Keyboard(CPU& cpu, InputReader& inputReader);
    void processInput();

private:
    CPU& cpu;
    InputReader& inputReader;
};

#endif // KEYBOARD_H