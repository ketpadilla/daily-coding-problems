/* // * PROBLEM :: October 13, 2024
  Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

  Note. Node class and test code is provided beforehand
*/


#include "./includes/helper.h"
#include <cassert>

int main() { //test program
  system("clear");

  Node* node = new Node("root", new Node("left", new Node("left.left")), new Node("right"));
  string serializedData = serialize(node);
  Node* deserializedNode = deserialize(serializedData);

  assert(deserializedNode->left->left->info == "left.left"); //test case
  cout << "SERIALIZING AND DESERIALIZING A BINARY TREE" << endl //print output
    << "Serialized" << endl
    << ":: " << serializedData << endl << endl
    << "Deserialized (Test Passed)" << endl
    << ":: " << deserializedNode->left->left->info << " == 'left.left'" << endl
    << endl;

  delete node;
  return 0;
}

/* // * ANALYSIS
  Time complexity: O(n)
  Fastest possible: O(n)

  ! AI heavily used
  Logic:
  * Serialize 
    • Traverse the Tree: 
        Use a traversal method (commonly preorder traversal) to visit each node.
    • Store Node Values: 
        During traversal, store the node value in a stringstream (or equivalent) to act as a buffer.
    • Handle Empty Nodes: 
        For empty nodes (null children), store a placeholder string (e.g., "#" or "null").
    • Return Serialized String: 
        After the traversal, return the constructed string that represents the tree structure.
  
  * Deserialize 
    • Parse the Serialized String: 
        Split the serialized string into individual components (node values).
    • Reconstruct the Tree:
        - Create a new node for each value.
        - If a placeholder is encountered, create an empty node (or return nullptr).
        - Recursively build the left and right subtrees by continuing to process the remaining values.
    • Return the Root Node: 
        After reconstructing the tree, return the root node of the newly created binary tree.
*/