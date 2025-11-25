/*
 * ██     ██████ ██████ ▄████▄
 * ██      ▄▄▀▀    ▄██▀ ██▄▄██
 * ██████ ██████  ██▀   ▀█▄▄█▀
 * Author: Nicolás de Rivas Morillo
 *
 * File: Input BitStream implementation
 */

#include "BitInputStream.hpp"

int BitInputStream::readBit() {
    if (bitCount == 0) { // If there are no bits in the buffer read a whole byte
        char c;
        if (!in.get(c))
            return -1;
        buffer = static_cast<uint8_t>(c);
        bitCount = 8;
    }
    bitCount--;
    return (buffer >> bitCount) & 1; // Return the first bit
}

long long BitInputStream::readBits(int n) {
    long long result = 0;
    // Just a for... Reads bits while it cans
    for (int i = 0; i < n; i++) {
        int bit = readBit();
        if (bit == -1)
            return -1;
        result = (result << 1) | bit;
    }
    return result;
}
