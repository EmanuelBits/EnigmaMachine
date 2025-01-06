#include "ALU.h"

uint8_t ALU::mov(uint8_t& dest, uint8_t src) {
    dest = src;
    return dest;
}

uint8_t ALU::andOp(uint8_t dest, uint8_t src) {
    return dest & src;
}

uint8_t ALU::orOp(uint8_t dest, uint8_t src) {
    return dest | src;
}

uint8_t ALU::shr(uint8_t dest, uint8_t count) {
    return dest >> count;
}

uint8_t ALU::shl(uint8_t dest, uint8_t count) {
    return dest << count;
}