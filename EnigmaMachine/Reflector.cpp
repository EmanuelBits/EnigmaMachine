#include "Reflector.h"

std::vector<char> Reflector::wiring = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};

char Reflector::encode(char input) {
	int index = (input - 'A') % 26;
	return wiring[index];
}