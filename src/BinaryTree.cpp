/*
 * ██     ██████ ██████ ▄████▄
 * ██      ▄▄▀▀    ▄██▀ ██▄▄██
 * ██████ ██████  ██▀   ▀█▄▄█▀
 * Author: Nicolás de Rivas Morillo
 *
 * File: Trie implementation
 */

#include "BinaryTree.hpp"
#include <memory>
#include <vector>

using namespace std;

unsigned BinaryTreeNode::getMaxDepth() const { return this->maxDepth; }
BinaryTreeNode *BinaryTreeNode::getBackReference() const {
    return this->backReference;
}
unsigned BinaryTreeNode::getIdentifier() const {
    return this->value.identifier;
}
char BinaryTreeNode::getTerminator() const { return this->value.terminator; }

void dfs(const BinaryTreeNode *const node, vector<LZTuple> &v) {
    v[node->getIdentifier()] = LZTuple(
        node->getBackReference()->getIdentifier(), node->getTerminator());
    for (auto &ptr : node->children)
        dfs(ptr.get(), v);
}

std::vector<LZTuple> BinaryTreeNode::getLZTuples() {
    vector<LZTuple> response = vector<LZTuple>(this->totalTuples);
    response.reserve(this->maxDepth);
    for (auto &ptr : this->children)
        dfs(ptr.get(), response);
    return response;
}

bool BinaryTreeNode::addChild(std::string child) {
    BinaryTreeNode *currentNode = this;
    unsigned i, j;
    for (i = 0; i < child.size() - 1; ++i) {
        for (j = 0; j < currentNode->children.size() &&
                    currentNode->children[j]->value.terminator != child[i];
             ++j) {
        }
        if (j == currentNode->children.size())
            return false;
        currentNode = currentNode->children[j].get();
    }
    for (j = 0; j < currentNode->children.size() &&
                currentNode->children[j]->value.terminator != child[i];
         ++j) {
    }
    if (j != currentNode->children.size())
        return false;
    currentNode->children.push_back(
        std::unique_ptr<BinaryTreeNode>(new BinaryTreeNode(
            this->totalTuples, child[child.size() - 1], currentNode)));
    this->maxDepth =
        this->maxDepth > child.size() ? this->maxDepth : child.size();
    this->totalTuples++;
    return true;
}

unsigned BinaryTreeNode::getIdentifier(const std::string &key) const {
    BinaryTreeNode const *currentNode = this;
    unsigned j;
    for (unsigned i = 0; i < key.size(); ++i) {
        for (j = 0; j < currentNode->children.size() &&
                    currentNode->children[j]->value.terminator != key[i];
             ++j) {
        }
        if (j == currentNode->children.size())
            return 0;
        currentNode = currentNode->children[j].get();
    }
    return currentNode->getIdentifier();
}
