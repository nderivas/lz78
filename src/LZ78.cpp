/*
 * ██     ██████ ██████ ▄████▄
 * ██      ▄▄▀▀    ▄██▀ ██▄▄██
 * ██████ ██████  ██▀   ▀█▄▄█▀
 * Author: Nicolás de Rivas Morillo
 *
 * File: LZ78 algorithm implementation
 */

#include "LZ78.hpp"
#include "BinaryTree.hpp"
#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void encode(istream &in, ostream &out) {
    BinaryTreeNode root = BinaryTreeNode();
    char c;
    string acumulated = "";
    while (in.get(c)) {
        acumulated += c;
        if (root.addChild(acumulated))
            acumulated = "";
    }
    auto tuples = root.getLZTuples();
    if (acumulated.size() > 0)
        tuples.push_back(LZTuple(root.getIdentifier(acumulated), '\0'));
    if (tuples.size() <= 1)
        return;
    BitOutputStream bs(out);
    bs.writeBits(tuples[1].terminator, 8);
    unsigned currentKeyLength = 1;
    for (unsigned i = 2; i < tuples.size(); ++i) {
        if (i > (static_cast<unsigned>(1) << currentKeyLength))
            currentKeyLength++;
        bs.writeBits(tuples[i].identifier, currentKeyLength);
        if (i != tuples.size() - 1 || acumulated.size() == 0)
            bs.writeBits(tuples[i].terminator, 8);
    }
}

void decode(istream &in, ostream &out) {
    BitInputStream bi(in);
    char firstChar = static_cast<char>(bi.readBits(8));
    out << firstChar;
    unordered_map<long long, string> sequences;
    sequences[0] = "";
    sequences[1] = "";
    sequences[1] += firstChar;
    unsigned currentKeyLength = 1;
    long long unsigned tuplesRead = 2;
    long long key;
    while (true) {
        key = bi.readBits(currentKeyLength);
        auto rawTerminator = bi.readBits(8);
        if (rawTerminator == -1)
            break;
        char terminator = static_cast<char>(rawTerminator);
        sequences[tuplesRead] = sequences[key];
        sequences[tuplesRead] += terminator;
        out << sequences[tuplesRead];
        tuplesRead++;
        if (tuplesRead > (static_cast<unsigned>(1) << currentKeyLength))
            currentKeyLength++;
    }
    if (key != -1)
        out << sequences[key];
}
