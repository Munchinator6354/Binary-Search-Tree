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

}
// ----------------------------------------------------------------------------



// ------------------------------  << operator --------------------------------
// << operator
// Description: 
//  - Overloaded output operator that takes the BinTree and outputs
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



// -------------------------------  retrieve  ---------------------------------
// retrieve
// Description: 
//  - 
// Precondition: 
//  - 
// Postcondition:
//  - 
// ----------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData& nodeToFind, NodeData*& nodeLocationFound) {

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
//  - NONE
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
