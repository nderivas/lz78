#include "BitOutputStream.hpp"

#include <cstdint>
#include <iostream>

void BitOutputStream::writeBit(int bit) {
    buffer = buffer << 1;
    if (bit)
        buffer |= 1;
    bitCount++;
    if (bitCount == 8) {
        out.put(static_cast<char>(buffer));
        bitCount = 0;
        buffer = 0;
    }
}

void BitOutputStream::writeBits(long long value, int logical_width) {
    for (int i = logical_width - 1; i >= 0; i--) {
        writeBit((value >> i) & 1);
    }
}

void BitOutputStream::flush() {
    if (bitCount > 0) {
        buffer = buffer << (8 - bitCount);
        out.put(static_cast<char>(buffer));
        buffer = 0;
        bitCount = 0;
    }
    out.flush();
}
