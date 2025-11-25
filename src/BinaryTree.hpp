/*
 * ██     ██████ ██████ ▄████▄
 * ██      ▄▄▀▀    ▄██▀ ██▄▄██
 * ██████ ██████  ██▀   ▀█▄▄█▀
 * Author: Nicolás de Rivas Morillo
 *
 * File: Trie definition
 */

#pragma once

#include <memory>
#include <string>
#include <vector>

// Represents a (id, char) tuple of the LZ78 algorithm
class LZTuple {
  public:
    unsigned identifier;
    char terminator;
    LZTuple(const unsigned identifier, const char terminator)
        : identifier(identifier), terminator(terminator) {}
    LZTuple() : identifier(0), terminator('\0') {}
};

class BinaryTreeNode;

using ChildrenVector = std::vector<std::unique_ptr<BinaryTreeNode>>;

// Represent a node of the Trie
class BinaryTreeNode {
    LZTuple value;                 // LZ78 tuple value of this node
    BinaryTreeNode *backReference; // Reference to the parent node
    // unsigned totalTuples, maxDepth; // Node counters
    unsigned totalTuples; // Node counters
    // BinaryTreeNode(unsigned identifier, char terminator,
    //                BinaryTreeNode *backReference)
    //     : value(identifier, terminator), backReference(backReference),
    //       totalTuples(0), maxDepth(0), children() {};
    BinaryTreeNode(unsigned identifier, char terminator,
                   BinaryTreeNode *backReference)
        : value(identifier, terminator), backReference(backReference),
          totalTuples(0), children() {};

  public:
    ChildrenVector children;
    // BinaryTreeNode()
    //     : value(0, '\0'), backReference(nullptr), totalTuples(1),
    //     maxDepth(0),
    //       children() {};
    BinaryTreeNode()
        : value(0, '\0'), backReference(nullptr), totalTuples(1), children() {};

    // Getters
    // unsigned getMaxDepth() const;
    BinaryTreeNode *getBackReference() const;
    unsigned getIdentifier() const;
    char getTerminator() const;
    std::vector<LZTuple> getLZTuples();

    // Add a child to this node
    bool addChild(std::string child);

    // Get the identifier of the node with given key
    unsigned getIdentifier(const std::string &key) const;
};
