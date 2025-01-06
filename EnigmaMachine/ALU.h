#ifndef ALU_H
#define ALU_H

#include <cstdint>

class ALU {
public:
    uint8_t mov(uint8_t& dest, uint8_t src);    // Simulate 'mov' operation
    uint8_t andOp(uint8_t dest, uint8_t src);   // Simulate 'and' operation
    uint8_t orOp(uint8_t dest, uint8_t src);    // Simulate 'or' operation
    uint8_t shr(uint8_t dest, uint8_t count);   // Simulate 'shr' (shift right) operation
    uint8_t shl(uint8_t dest, uint8_t count);   // Simulate 'shl' (shift left) operation
};

#endif // ALU_H