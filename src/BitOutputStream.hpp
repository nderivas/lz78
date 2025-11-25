/*
 * ██     ██████ ██████ ▄████▄
 * ██      ▄▄▀▀    ▄██▀ ██▄▄██
 * ██████ ██████  ██▀   ▀█▄▄█▀
 * Author: Nicolás de Rivas Morillo
 *
 * File: Output BitStream definition
 */

#include <cstdint>
#include <iostream>

// Allows the use of a datastream by bits
class BitOutputStream {
    std::ostream &out; // Datastream
    uint8_t buffer;    // Byte to use as buffer
    int bitCount;      // Current bitcount in the buffer

  public:
    // Constructor: Initializes variables
    BitOutputStream(std::ostream &os) : out(os), buffer(0), bitCount(0) {}
    // Desctructor: flushes data
    ~BitOutputStream() { flush(); }

    // Writes a bit to the stream (buffers it if needed)
    void writeBit(int bit);
    // Writes multiple bits to the stream (buffers them if needed)
    void writeBits(long long value, int logical_width);
    // Flushes the buffer to the stream
    void flush();
};
