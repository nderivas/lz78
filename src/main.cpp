/*
 * ██     ██████ ██████ ▄████▄
 * ██      ▄▄▀▀    ▄██▀ ██▄▄██
 * ██████ ██████  ██▀   ▀█▄▄█▀
 * Author: Nicolás de Rivas Morillo
 *
 * File: Main entrypoint
 */

#include "LZ78.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    // If not enough arguments
    if (argc != 2) {
        cerr << "USAGE: " << argv[0] << " [-c|-d]" << endl;
        return 1;
    }
    // Check if we have to compress or decompress
    if (string(argv[1]) == "-c")
        encode(cin, cout);
    else if (string(argv[1]) == "-d")
        decode(cin, cout);
    else { // If option is not recognized print usage
        cerr << "USAGE: " << argv[0] << " [-c|-d]" << endl;
        return 1;
    }
    return 0;
}
