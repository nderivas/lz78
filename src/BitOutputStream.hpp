#include <cstdint>
#include <iostream>

class BitOutputStream {
    std::ostream &out;
    uint8_t buffer;
    int bitCount;

  public:
    BitOutputStream(std::ostream &os) : out(os), buffer(0), bitCount(0) {}
    ~BitOutputStream() { flush(); }

    void writeBit(int bit);
    void writeBits(long long value, int logical_width);
    void flush();
};
