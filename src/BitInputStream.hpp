/*
 * ██     ██████ ██████ ▄████▄
 * ██      ▄▄▀▀    ▄██▀ ██▄▄██
 * ██████ ██████  ██▀   ▀█▄▄█▀
 * Author: Nicolás de Rivas Morillo
 *
 * File: Input BitStream definition
 */

#pragma once

#include <cstdint>
#include <iostream>

// Allows the reading of bits in a datastream
class BitInputStream {
    std::istream &in; // Datastream to use
    uint8_t buffer;   // Reading buffer
    int bitCount;     // Current bits in the buffer

  public:
    // Constructor - Initializes member variables
    BitInputStream(std::istream &is) : in(is), buffer(0), bitCount(0) {}

    // Reads a bit from the stream
    int readBit();
    // Reads n bits from the stream
    long long readBits(int n);
};
