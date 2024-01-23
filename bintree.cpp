// ------------------------------ bintree.cpp --------------------------------
// Ryan Isaacson CSS502
// Date of creation: 01/20/2024
// Date of Last Modification: 01/26/2024
// ----------------------------------------------------------------------------
// Purpose: This file is the function definition file for the BinTree class. 
// 
// ----------------------------------------------------------------------------
// Notes: 
// ----------------------------------------------------------------------------

#include "bintree.h"

// ------------------------------  >> operator --------------------------------
// >> operator
// Description: 
//  - Overloaded input operator
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
istream& operator>>(istream input, BinTree& b) {
  string charSet;
  // While we get pairs of numbers appropriately, set up those Terms
  while (input >> charSet && charSet != "$$") {
    // take the charSet and insert it into the tree
    // need to write the insert function
  }
  return input;
}
// ----------------------------------------------------------------------------



// ------------------------------  << operator --------------------------------
// << operator
// Description: 
//  - Overloaded output operator
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
ostream& operator<<(ostream& output, const BinTree& b) {
  
}
// ----------------------------------------------------------------------------

// --------------------------  Default Constructor  ----------------------------
// Default Constructor
// Description: 
//  - Default constructor for BinTree class
// Precondition: 
//  - The BinTree doesn't exist and has no Nodes
// Postcondition:
//  - The Bintree exists now with no Nodes. The root is equal to nullptr
// ----------------------------------------------------------------------------
BinTree::BinTree() {
  root = nullptr;
}
// ----------------------------------------------------------------------------


// ---------------------------  Copy Constructor  -----------------------------
// Default Constructor
// Description: 
//  - Copy constructor for BinTree class
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
BinTree::BinTree(const BinTree& b) {
  
}
// ----------------------------------------------------------------------------


// ------------------------------  Destructor  --------------------------------
// Destructor
// Description: 
//  - Destructor for BinTree class
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
BinTree::~BinTree() {
  
}
// ----------------------------------------------------------------------------



// ------------------------------  = operator  --------------------------------
// = operator
// Description: 
//  - 
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree& b) {

}
// ----------------------------------------------------------------------------



// -----------------------------  == operator  --------------------------------
// operator ==
// Description: 
//  - 
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
bool BinTree::operator==(const BinTree& b) const {

}
// ----------------------------------------------------------------------------

// -----------------------------  != operator  --------------------------------
// != operator
// Description: 
//  - 
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree& b) const {

}
// ----------------------------------------------------------------------------



// -------------------------------  getHeight  --------------------------------
// getHeight
// Description: 
//  - 
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
int BinTree::getHeight(const NodeData &nodeToFind) const {

}
// ----------------------------------------------------------------------------



// --------------------------------  insert  ----------------------------------
// insert
// Description: 
//  - 
// Precondition: 
//  - The BinTree exists and has >= 0 Nodes already.
// Postcondition:
//  - The BinTree exists and has 1 more node, with the data passed in inserted
//    in a Binary Tree ordering fashion.
// ----------------------------------------------------------------------------
bool BinTree::insert(NodeData* nd) {
  if (root == nullptr) {
    root = new Node();
    root->left = nullptr;
    root->data = nd;
    root->right = nullptr;
  } else if (*nd < *root->data) {
    insertHelper(root->left, nd);
  } else {
    insertHelper(root->right, nd);
  }
}
// ----------------------------------------------------------------------------



// --------------------------------  insertH  ---------------------------------
// insertH
// Description: 
//  - Helper function for recursive nature of insert function. Has extra 
//    parameter to account for the node being passed in if it is not the root.
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
bool BinTree::insertHelper(Node*& node, NodeData* nd) {
  if (node == nullptr) {
    node = new Node();
    node->left = nullptr;
    node->data = nd;
    node->right = nullptr;
    return true;
  } else if (*nd < *node->data) {
    return insertHelper(node->left, nd);
  } else {
    return insertHelper(node->right, nd);
  }
  return false;
}
// ----------------------------------------------------------------------------



// -------------------------------  retrieve  ---------------------------------
// retrieve
// Description: 
//  - If the passed in target NodeData exists in the BinTree, a value of true 
//    is returned and the found parameter is set to be the accessible point 
//    of that NodeData object. If the target NodeData does not exist in the 
//    BinTree, a value of false is returned and the found parameter is simply 
//    garbage. This function relies on it's helper function to recursively 
//    focus on one Node at a time, starting with the root Node.
// Precondition: 
//  - The BinTree exists and has >= 0 Nodes in it, each with their own 
//    NodeData object and respective data within.
// Postcondition:
//  - The BinTree exists and either true or false is returned depending on if 
//    the target value was found, true if found, false if not. If the NodeData 
//    was found, the found parameter is pointed to that NodeData. If the 
//    NodeData was not found, then garbage data fills the found parameter.
// ----------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData& target, NodeData*& found) {
  return retrieveHelper(root, target, found);
}
// ----------------------------------------------------------------------------



// ---------------------------  retrieveHelper  -------------------------------
// retrieveHelper
// Description: 
//  - This function is the recursive helper function for the retrieve function.
//    It is called by the retrieve function. If the root is nullptr, we return 
//    false and did not find the target NodeData. If the target NodeData 
//    matches the passed in Node's NodeData, set the found parameter to the 
//    access location of the NodeData and return true. Otherwise we keep 
//    recursively searching left and right until we traverse the whole BinTree
// Precondition: 
//  - The retrieve function was called
// Postcondition:
//  - The BinTree exists and either true or false is returned depending on if 
//    the target value was found, true if found, false if not. If the NodeData 
//    was found, the found parameter is pointed to that NodeData. If the 
//    NodeData was not found, then garbage data fills the found parameter.
// ----------------------------------------------------------------------------
bool BinTree::retrieveHelper(Node* curr, const NodeData& target, NodeData*& found) {
  if (curr == nullptr) {
    found = nullptr; // do i need this line?????
    return false;
  } else if (*curr->data == target) {
    *found = *curr->data;
    return true;
  } else if (*curr->data < target) {
    return retrieveHelper(curr->left, target, found);
  } else {
    return retrieveHelper(curr->right, target, found);
  }
}
// ----------------------------------------------------------------------------



// -----------------------------  bstreeToArray  ------------------------------
// bstreeToArray
// Description: 
//  - 
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* []) {

}
// ----------------------------------------------------------------------------



// -----------------------------  arrayToBSTree  ------------------------------
// arrayToBSTree
// Description: 
//  - 
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData* []) {

}
// ----------------------------------------------------------------------------



// ----------------------------  displaySideways  -----------------------------
// displaySideways
// Description: 
//  - 
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
void BinTree::displaySideways() const {
  sideways(root, 0);
}
// ----------------------------------------------------------------------------



//------------------------------ sideways -------------------------------------
// sideways
// Description:
//  - Helper method for displaySideways
// Precondition: 
//  - 
// Postcondition:
//  - BinTree remains unchanged
// ----------------------------------------------------------------------------
void BinTree::sideways(Node* current, int level) const {
  if (current != NULL) {
    level++;
    sideways(current->right, level);

    // indent for readability, 4 spaces per depth level 
    for (int i = level; i >= 0; i--) {
      cout << "    ";
    }

    cout << *current->data << endl;        // display information of object
    sideways(current->left, level);
  }
}
// ----------------------------------------------------------------------------



//----------------------------- printInOrder ----------------------------------
// printInOrder
// Description:
//  - 
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
void BinTree::printInOrder(ostream& output, Node* node) const {
  if (node != nullptr) {
    printInOrder(output, node->left);
    output << *node->data << " ";
    printInOrder(output, node->right);
  }
}
// ----------------------------------------------------------------------------
