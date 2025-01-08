#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <vector>

class Reflector {
public:
    Reflector() = default;
    static char encode(char input);

private:
    static std::vector<char> wiring;
};

#endif // REFLECTOR_H
