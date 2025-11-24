#pragma once

#include <cstdint>
#include <iostream>

class BitInputStream {
    std::istream &in;
    uint8_t buffer;
    int bitCount;

  public:
    BitInputStream(std::istream &is) : in(is), buffer(0), bitCount(0) {}
    int readBit();
    long long readBits(int n);
};
