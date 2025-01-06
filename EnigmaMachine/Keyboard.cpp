#include "Keyboard.h"

Keyboard::Keyboard(CPU& cpu, InputReader& inputReader)
    : cpu(cpu), inputReader(inputReader) {
}

void Keyboard::processInput() {
    while (inputReader.hasMoreCharacters()) {
        char ch = inputReader.getNextCharacter();
        if (ch != '\0') {
            cpu.processCharacter(ch);
        }
    }
}