# ifndef BIN_TREE_H
#define BIN_TREE_H

#include "nodedata.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class BinTree {

  struct Node {
    NodeData* data;
    Node* left;
    Node* right;
  };

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
  int getHeight(const NodeData &nodeToFind) const;
  bool retrieve(const NodeData& nodeToFind, NodeData*& nodeLocationFound);
  void bstreeToArray(NodeData* []);
  void arrayToBSree(NodeData* []);

private:
  Node* root;


};

#endif