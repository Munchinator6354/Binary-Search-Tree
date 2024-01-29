// ------------------------------ bintree.h --------------------------------
// Ryan Isaacson CSS502
// Date of creation: 01/20/2024
// Date of Last Modification: 01/26/2024
// ----------------------------------------------------------------------------
// Purpose: This file is the function declaration file for the BinTree class. 
// 
// ----------------------------------------------------------------------------
// Notes: 
// ----------------------------------------------------------------------------

#ifndef BIN_TREE_H
#define BIN_TREE_H

#include "nodedata.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class BinTree {

  friend istream& operator>>(istream& input, BinTree& b);
  friend ostream& operator<<(ostream& output, const BinTree& b);

public:
  BinTree();
  BinTree(const BinTree& b);
  ~BinTree();

  // Assignment Operator
  BinTree& operator=(const BinTree& b);

  // Equality and Inequality Operators
  bool operator==(const BinTree& b) const;
  bool operator!=(const BinTree& b) const;

  // Others
  void arrayToBSTree(NodeData* []);
  void bstreeToArray(NodeData* []);
  void displaySideways() const;
  int getHeight(const NodeData& target) const;
  bool insert(NodeData* nd); // bool return is to check that a ndoe was inserted and it wasn't a duplicate
  bool isEmpty() const;
  bool retrieve(const NodeData& target, NodeData*& found) const;
  void makeEmpty();

private:
  struct Node {
    Node* left;
    NodeData* data;
    Node* right;
  };

  Node* root;

  // utility functions
  Node* findNode(const NodeData& target) const;
  Node* findNodeHelper(Node* node, const NodeData& target) const;
  int getHeightHelper(const Node* node) const;
  void inorderHelper( ... ) const;
  bool insertHelper(Node*& node, NodeData* nd);
  void printInOrder(ostream& output, Node* node) const;
  bool retrieveHelper(Node* curr, const NodeData& target, NodeData*& found) const;
  void sideways(Node*, int) const;			// provided below, helper for displaySideways()
  bool traverseAndCompare(const Node* node, const Node* otherNode) const;
  void traverseAndCopy(Node* otherTreeNode);
  void traverseAndMakeEmpty(Node*& node);
  int getHeightOfNode(const Node node);


};

#endif