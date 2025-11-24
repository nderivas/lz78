#include "BitInputStream.hpp"

int BitInputStream::readBit() {
    if (bitCount == 0) {
        char c;
        if (!in.get(c))
            return -1;
        buffer = static_cast<uint8_t>(c);
        bitCount = 8;
    }
    bitCount--;
    return (buffer >> bitCount) & 1;
}

long long BitInputStream::readBits(int n) {
    long long result = 0;
    for (int i = 0; i < n; i++) {
        int bit = readBit();
        if (bit == -1)
            return -1;
        result = (result << 1) | bit;
    }
    return result;
}
