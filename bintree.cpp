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

// // ------------------------------  >> operator --------------------------------
// // >> operator
// // Description: 
// //  - Overloaded input operator
// // Precondition: 
// //  - 
// // Postcondition:
// //  - 
// // ----------------------------------------------------------------------------
// istream& operator>>(istream& input, BinTree& b) {
//   string charSet;
//   // While we get pairs of numbers appropriately, set up those Terms
//   while (input >> charSet && charSet != "$$") {
//     // take the charSet and insert it into the tree
//     // need to write the insert function
//   }
//   return input;
// }
// // ----------------------------------------------------------------------------



// ------------------------------  << operator --------------------------------
// << operator
// Description: 
//  - Overloaded output operator that takes the BinTree as a parameter and 
//    prints out it's data via an in-order traversal in the form:
//    "data1 data2 data3 data5 data6 data7 data8 data9" ...etc
// Precondition: 
//  - The BinTree exists and has >= 0 Nodes
// Postcondition:
//  - The BinTree is unchanged.
// ----------------------------------------------------------------------------
ostream& operator<<(ostream& output, const BinTree& b) {
  b.printInOrder(output, b.root);
  return output;
}
// ----------------------------------------------------------------------------



//----------------------------- printInOrder ----------------------------------
// printInOrder
// Description:
//  - Helper fucntion for the << output operator overload that utilizes an 
//    in-order recursive tree traversal to concatenate each Node's NodeData's 
//    data value into the output stream one Node at a time
// Precondition: 
//  - The output stream could be empty or it could have any number of previous 
//    Node's NodeData data that was already sent to it so far. The first 
//    time this function is called the root Node of the BinTree is passed as 
//    the node parameter
// Postcondition:
//  - The current Node's NodeData data has been added to the output stream to 
//    be used by the << operator overload. This function ends up being called 
//    over and over until every Node in the tree has been visited
// ----------------------------------------------------------------------------
void BinTree::printInOrder(ostream& output, Node* node) const {
  if (node != nullptr) {
    printInOrder(output, node->left);
    output << *node->data << " ";
    printInOrder(output, node->right);
  }
  return;
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
  root = nullptr;
  traverseAndCopy(b.root);
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
  makeEmpty();
}
// ----------------------------------------------------------------------------



// ------------------------------  = operator  --------------------------------
// = operator
// Description: 
//  - This operator overload is used to assign the contents of the passed in 
//    BinTree to this Bintree. It utilizes a deep copy method and makes sure 
//    to empty this BinTree of any Nodes and NodeData objects before beginning 
//    the copy.
// Precondition: 
//  - This BinTree and the passed in BinTree exist and both have >= 0 Nodes
// Postcondition:
//  - This BinTree contents appear to be identical to the passed in BinTree
// ----------------------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree& b) {
  if (this != &b) {     // avoid self-assignment
    traverseAndMakeEmpty(root);   // make this tree empty
    traverseAndCopy(b.root);     // copy the other tree into this tree       
  } 
  return *this;
}
// ----------------------------------------------------------------------------

// dup = T
// dup = dup

// -----------------------------  == operator  --------------------------------
// operator ==
// Description: 
//  - Compares two Bintree's to see if they are identical to each other. 
//    Returns true if the BinTree's are identical. Returns false if the 
//    BinTree's are not identical
// Precondition: 
//  - Both Bintrees exist and have >0 Nodes
// Postcondition:
//  - Both Bintrees exist and have >0 Nodes. 
// ----------------------------------------------------------------------------
bool BinTree::operator==(const BinTree& b) const {
  return traverseAndCompare(root, b.root);
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
  return !(*this == b);
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
void BinTree::arrayToBSTree(NodeData* arr[]) {
  cout << "I'm inside the arrayToBSTree function: " << endl;

  

  // Count how many valid NodeData pointers there are
  int numND = 0;
  
  for (int i = 0; i < 100; i++) {
    if (arr[i] != NULL) {
        numND++;
    }
  }

  int centerND = numND / 2;

  root = arr[numND];
  
}
// ----------------------------------------------------------------------------



// -----------------------------  bstreeToArray  ------------------------------
// bstreeToArray
// Description: 
//  - Takes the NodeData pointers out of the BinTree and puts them into the 
//    passed in array. Utilizes the in-order traverseAndArrayify function for 
//    the array building. Utilizes the traverseAndMakeEmpty function to empty 
//    the BinTree of all Nodes and NodeData objects afterwards.
// Precondition: 
//  - The BinTree has >0 Nodes. The passed in array is filled to a static 
//    quantity of 100 NULL NodaData* spaces able to be filled
// Postcondition:
//  - The BinTree is empty and the passed in array is filled with pointers to 
//    the NodeData objects that were originally in the BinTree
// ----------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* arr[]) {
  int index = 0;
  traverseAndArrayify(root, arr, index);
  traverseAndMakeEmpty(root);
}
// ----------------------------------------------------------------------------



// --------------------------  traverseAndArrayify  ---------------------------
// traverseAndArrayify
// Description: 
//  - This function starts out expecting the root Node of the BinTree, an 
//    array statically allocated to 100 NodeData pointers each as NULL, and 
//    the current index being 0. It then recursively traverses the BinTree 
//    and inserts the NodeData objects into the array. The function does no 
//    insertion into the array if it comes accross an empty Node, including 
//    if trying to arrayify an empty BinTree
// Precondition: 
//  - BinTree has >0 Nodes. The passed in array is fille to a static amount 
//    of 100 NULL NodeData* spaces able to be filled. The index is initially 0
// Postcondition:
//  - All NodeData's in the BinTree have been inserted into the array
// ----------------------------------------------------------------------------
void BinTree::traverseAndArrayify(Node* node, NodeData* arr[], int& index) {
  if (node == nullptr) {
    return;
  }
  traverseAndArrayify(node->left, arr, index);
  arr[index++] = node->data;
  traverseAndArrayify(node->right, arr, index);
}
// ----------------------------------------------------------------------------



// ----------------------------  displaySideways  -----------------------------
// displaySideways
// Description: 
//  - Function provided by the professor to display the contents of the 
//    BinTree in a sideways fashion
// Precondition: 
//  - NONE
// Postcondition:
//  - BinTree remains unchanged and contents are visually output to user
// ----------------------------------------------------------------------------
void BinTree::displaySideways() const {
  sideways(root, 0);
}
// ----------------------------------------------------------------------------



// ------------------------------  findNode  ---------------------------------
// findNode
// Description: 
//  - Looks for a Node in the BinTree that has a NodeData object that 
//    matches the passed NodeData object. If the Node exists, a pointer to 
//    that Node is returned. If the Node does not exist then nullptr is 
//    returned;
// Precondition: 
//  - 
// Postcondition:
//  - The BinTree is unchanged
// ----------------------------------------------------------------------------
BinTree::Node* BinTree::findNode(const NodeData& target) const {
  return findNodeHelper(root, target);
}
// ----------------------------------------------------------------------------



// -------------------------  findNodeHelper  ---------------------------------
// findNodeHelper
// Description: 
//  - Looks for a Node in the BinTree that has a NodeData object that 
//    matches the passed NodeData object. If the Node exists, a pointer to 
//    that Node is returned. If the Node does not exist then nullptr is 
//    returned;
// Precondition: 
//  - 
// Postcondition:
//  - The BinTree is unchanged
// ----------------------------------------------------------------------------
BinTree::Node* BinTree::findNodeHelper(Node* node, const NodeData& target) const {
  if (node == nullptr) {
    return nullptr;
  }
  if (*node->data == target) {
    return node;
  }
  Node* leftSearch = findNodeHelper(node->left, target);
  if (leftSearch != nullptr) {
    return leftSearch;
  }
  Node* rightSearch = findNodeHelper(node->right, target);
  return rightSearch;
}
// ----------------------------------------------------------------------------



// ------------------------------  getHeight  ---------------------------------
// getHeight
// Description: 
//  - Returns the height of the Node in the BinTree that houses the NodeData 
//    object passed in as a parameter. A leaf Node in the tree is considered a 
//    height of 1 and every Node above that is an additional +1 height. If the
//    target NodeData does not exist in the BinTree, the function returns a 
//    height of 0
// Precondition: 
//  - The BinTree exists and has >= 0 Nodes. The NodeData object may or may 
//    not exist within the BinTree
// Postcondition:
//  - The BinTree is unchanged
// ----------------------------------------------------------------------------
int BinTree::getHeight(const NodeData& target) const {
  // Create a pointer to the potential Node housing the target NodeData
  // If it doesn't exist, nullptr is returned
  Node* targetNode = findNode(target);
  // // if the Node exists, return the height of the Node
  if (targetNode != nullptr) {
    return getHeightHelper(targetNode);
  }
  // Height is 0 if Node not found
  return 0;
}
// ----------------------------------------------------------------------------



// ---------------------------  getHeightHelper  ------------------------------
// getHeightHelper
// Description: 
//  - Recursive helper function for getHeight. 
// Precondition: 
//  - This function is only called if BinTree has >= 1 Nodes.
// Postcondition:
//  - The BinTree is unchanged
// ----------------------------------------------------------------------------
int BinTree::getHeightHelper(const Node* node) const {
  if (node == nullptr) {
    return 0;
  }
  int leftHeight = getHeightHelper(node->left);
  int rightHeight = getHeightHelper(node->right);
  return max(leftHeight, rightHeight) + 1;
}
// ----------------------------------------------------------------------------



// --------------------------------  insert  ----------------------------------
// insert
// Description: 
//  - Takes the NodeData pointer passed as a parameter and if it's value 
//    doesn't already exist in the BinTree, it will create a new Node and 
//    insert that NodeData into the BinTree with the passed in NodeData data 
//    value. If the NodeData is a duplicate and already exists in the 
//    BinTree, the function will do no insertion and will return false.
// Precondition: 
//  - The BinTree exists and has >= 0 Nodes.
// Postcondition:
//  - The BinTree exists and has 1 more node if the data passed was not a 
//    duplicate already found in the BinTree. If it is a duplicate the BinTree 
//    remains unchanged
// ----------------------------------------------------------------------------
bool BinTree::insert(NodeData* nd) {
  return insertHelper(root, nd);
}
// ----------------------------------------------------------------------------



// -----------------------------  insertHelper  -------------------------------
// insertHelper
// Description: 
//  - Helper function for recursive nature of insert function. Has extra 
//    parameter to account for the Node space being looked at. Uses a pre-order 
//    traversal of the BinTree from the point of the node passed in
// Precondition: 
//  - The BinTree exists and has >= 0 Nodes.
// Postcondition:
//  - The BinTree exists and has 1 more node if the data passed was not a 
//    duplicate already found in the BinTree. If it is a duplicate the BinTree 
//    remains unchanged
// ----------------------------------------------------------------------------
bool BinTree::insertHelper(Node*& node, NodeData* nd) {
  // Pre-order traversal
  if (node == nullptr) { // found empty space
    node = new Node();
    node->left = nullptr;
    // THIS IS THE NEW CODE I'M ADDING TO SEE ABOUT DEEP COPYING THE NODE DATA's
    NodeData* newND = new NodeData(*nd);
    node->data = newND;
    // node->data = nd; // COMMENTING THIS OUT, I THINK THIS IS SHALLOW COPYING
    node->right = nullptr;
    return true; // successful insertion
  } else if (*nd < *node->data) { // found a node with a higher data, must insert left
    return insertHelper(node->left, nd);
  } else if (*nd > *node->data) { // found a node with a lower data, must insert right
    return insertHelper(node->right, nd);
  } 
  return false; // in an identical data case, we do nothing
}
// ----------------------------------------------------------------------------



// -------------------------------  isEmpty  ----------------------------------
// isEmpty
// Description: 
//  - Returns true if the BinTree is empty of Nodes. Returns false if there is 
//    1+ Nodes
// Precondition: 
//  - The BinTree exists and has >= 0 Nodes.
// Postcondition:
//  - The BinTree remains unchanged
// ----------------------------------------------------------------------------
bool BinTree::isEmpty() const {
  return (root == nullptr);
}
// ----------------------------------------------------------------------------



// -------------------------------  makeEmpty  --------------------------------
// makeEmpty
// Description: 
//  - This function empties the Bin Tree of all it's Nodes and NodeData 
//    objects utilizing a helper function of traverseAndMakeEmpty
// Precondition: 
//  - The BinTree has >= 0 Nodes
// Postcondition:
//  - The BinTree is empty, all memory on the heap that was utilized has been 
//    deallocated and the root is set to nullptr
// ----------------------------------------------------------------------------
void BinTree::makeEmpty() {
  traverseAndMakeEmpty(root);
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
bool BinTree::retrieve(const NodeData& target, NodeData*& found) const {
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
bool BinTree::retrieveHelper(Node* curr, const NodeData& target, NodeData*& found) const {
  // Pre-order traversal
  if (curr == nullptr) {
    return false;
  } else if (*curr->data == target) {
    found = curr->data;
    return true;
  } else if (target < *curr->data) {
    return retrieveHelper(curr->left, target, found);
  } else {
    return retrieveHelper(curr->right, target, found);
  }
}
// ----------------------------------------------------------------------------



//------------------------------ sideways -------------------------------------
// sideways
// Description:
//  - Helper method for displaySideways
// Precondition: 
//  - The displaySideways function was called
// Postcondition:
//  - BinTree remains unchanged. Contents are visually displayed to the user
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



// ---------------------------  traverseAndCompare  ---------------------------
// traverseAndCompare
// Description: 
//  - Traverses the BinTree and compares the NodeData objects in each Node. 
//    Returns true if the trees are identical. Returns false if there is a
//    discrepancy.
// Precondition: 
//  - The passed in Nodes are the root of both BinTree's whether they are 
//    empty or not
// Postcondition:
//  - The BinTree's are unchanged, but the function returns true if the 
//    BinTree's are identical and false if they are not identical
// ----------------------------------------------------------------------------
bool BinTree::traverseAndCompare(const Node* node, const Node* otherNode) const {
  // If both BinTree's are empty, they're equal
  if (node == nullptr && otherNode == nullptr) {
    return true;
  }
  // If one of the two Node's is nullptr and the other is not, they are not equal
  if ((node == nullptr && otherNode != nullptr) || (node != nullptr && otherNode == nullptr)) {
    return false;
  } 
  // Both nodes exist, compare their NodeData's
  if (*node->data != *otherNode->data) {
    return false;
  }
  // Otherwise these two nodes exist and are equal. Recurse both sides of the BinTree and return all comparisons.
  return traverseAndCompare(node->left, otherNode->left) && traverseAndCompare(node->right, otherNode->right);
}
// ----------------------------------------------------------------------------



// ----------------------------  traverseAndCopy  -----------------------------
// traverseAndCopy
// Description: 
//  - Traverses the BinTree utilizing a pre-order traversal 
// Precondition: 
//  - The BinTree has been emptied and has 0 Nodes and 0 NodeData objects
// Postcondition:
//  - The Nodes and NodeData objets in this BinTree are identical to the 
//    passed in BinTree via a deep copy
// ----------------------------------------------------------------------------
void BinTree::traverseAndCopy(Node* otherTreeNode) { // gets passed the root node of the other BinTree
  //Pre-order traversal
  // If the other BinTree's Node space is occupied, we insert that NodeData into this BinTree
  if (otherTreeNode != nullptr) {
    insert(otherTreeNode->data);
    // Recursing left
    if (otherTreeNode->left != nullptr) {
      traverseAndCopy(otherTreeNode->left);
    }
    // Recursing right
    if (otherTreeNode->right != nullptr) {
      traverseAndCopy(otherTreeNode->right);
    }
  } 
}
// ----------------------------------------------------------------------------



// -------------------------  traverseAndMakeEmpty  ---------------------------
// traverseAndMakeEmpty
// Description: 
//  - Traverses the BinTree utilizing a post-order traversal and destroys all 
//    NodeData objects and Nodes within the tree, successfully deallocating 
//    their memory from the heap and leaving the root as nullptr due to 
//    passing a reference to a pointer
// Precondition: 
//  - The BinTree has >= 0 Nodes
// Postcondition:
//  - The BinTree is empty, all memory on the heap that was utilized has been 
//    deallocated and the root is set to nullptr
// ----------------------------------------------------------------------------
void BinTree::traverseAndMakeEmpty(Node*& node) {
  // Post-order traversal
  if (node == nullptr) { // A UW Bothell tutor told me to put this here, I don't think it was needed
    return;
  }
  if (node != nullptr) {
    
    if (node->left != nullptr) {
        traverseAndMakeEmpty(node->left);
    }
    if (node->right != nullptr) {
        traverseAndMakeEmpty(node->right);
    }
    // At a leaf
    delete node->data;
    node->data = nullptr;
    delete node;
    node = nullptr;
  }
}
// ----------------------------------------------------------------------------

