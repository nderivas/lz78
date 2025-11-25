/*
 * ██     ██████ ██████ ▄████▄
 * ██      ▄▄▀▀    ▄██▀ ██▄▄██
 * ██████ ██████  ██▀   ▀█▄▄█▀
 * Author: Nicolás de Rivas Morillo
 *
 * File: Output BitStream implementation
 */

#include "BitOutputStream.hpp"

#include <iostream>

void BitOutputStream::writeBit(int bit) {
    buffer = buffer << 1; // Reserve space for the new bit
    if (bit)              // Add the bit
        buffer |= 1;
    bitCount++;          // Increase current bit count
    if (bitCount == 8) { // If im ready to flush do it
        out.put(static_cast<char>(buffer));
        bitCount = 0;
        buffer = 0;
    }
}

void BitOutputStream::writeBits(long long value, int logical_width) {
    // Just a for loop...
    for (int i = logical_width - 1; i >= 0; i--) {
        writeBit((value >> i) & 1);
    }
}

void BitOutputStream::flush() {
    // Flush the buffer even if its not full (0s for padding)
    if (bitCount > 0) {
        buffer = buffer << (8 - bitCount);
        out.put(static_cast<char>(buffer));
        buffer = 0;
        bitCount = 0;
    }
    out.flush();
}
