#ifndef PLUG_H
#define PLUG_H

class Plug {
public:
    Plug(char letter1, char letter2) : letter1(letter1), letter2(letter2) {}

    char getLetter1() const { return letter1; }
    char getLetter2() const { return letter2; }

private:
    char letter1, letter2;
};

#endif // PLUG_H