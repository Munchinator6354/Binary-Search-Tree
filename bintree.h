# ifndef BIN_TREE_H
#define BIN_TREE_H

#include "nodedata.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class BinTree {

  friend istream operator>>(istream& input, BinTree& b);
  friend ostream& operator<<(ostream& output, const BinTree& b);

public:
  BinTree();
  BinTree(const BinTree& b);
  ~BinTree();
  bool isEmpty() const;
  void makeEmpty();

  // Assignment Operator
  BinTree& operator=(const BinTree& b);

  // Equality and Inequality Operators
  bool operator==(const BinTree& b) const;
  bool operator!=(const BinTree& b) const;

  // Others
  void arrayToBSTree(NodeData* []);
  void bstreeToArray(NodeData* []);
  void displaySideways() const;
  int getHeight(const NodeData &nodeToFind) const;
  bool insert(NodeData*);
  bool retrieve(const NodeData& nodeToFind, NodeData*& nodeLocationFound) const;

private:
  struct Node {
    NodeData* data;
    Node* left;
    Node* right;
  };

  Node* root;

  // utility functions
  void inorderHelper( ... ) const;
  void sideways(Node*, int) const;			// provided below, helper for displaySideways()

};

#endif