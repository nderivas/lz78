#pragma once

#include <memory>
#include <string>
#include <vector>

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

class BinaryTreeNode {
    LZTuple value;
    BinaryTreeNode *backReference;
    unsigned totalTuples, maxDepth;
    BinaryTreeNode(unsigned identifier, char terminator,
                   BinaryTreeNode *backReference)
        : value(identifier, terminator), backReference(backReference),
          totalTuples(0), maxDepth(0), children() {};

  public:
    ChildrenVector children;
    BinaryTreeNode()
        : value(0, '\0'), backReference(nullptr), totalTuples(1), maxDepth(0),
          children() {};
    unsigned getMaxDepth() const;
    BinaryTreeNode *getBackReference() const;
    unsigned getIdentifier() const;
    char getTerminator() const;
    std::vector<LZTuple> getLZTuples();
    bool addChild(std::string child);
    unsigned getIdentifier(const std::string &key) const;
};
