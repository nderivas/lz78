#include "LZ78.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "USO: " << argv[0] << " [-c|-d]" << endl;
        return 1;
    }
    if (string(argv[1]) == "-c")
        encode(cin, cout);
    else if (string(argv[1]) == "-d")
        decode(cin, cout);
    else {
        cerr << "USO: " << argv[0] << " [-c|-d]" << endl;
        return 1;
    }
    return 0;
}
