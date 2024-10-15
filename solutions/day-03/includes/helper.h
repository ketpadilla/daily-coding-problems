// HEADER FILE: helper.h

#ifndef H_Helper
#define H_Helper 

#include <iostream>
#include <sstream>
#include <queue>
#include "./node.h"
using namespace std;

/* // * NOTE
  serialize and deserialize uses preorder traversal
    :: info, left, right
*/

string serialize(Node* root) {
  if (root == nullptr) return "# "; //base case

    //traversal
  stringstream ss;
  ss << root->info << " ";
  ss << serialize(root->left);
  ss << serialize(root->right);
  
  return ss.str();
}//end serialize

Node* deserialize(istringstream& iss) {
  string info;
  if (info == "#" || !(iss >> info)) {
    return nullptr; //base case
  }

    //traversal
  Node* node = new Node(info);
  node->left = deserialize(iss);
  node->right = deserialize(iss);

  return node;
}//end deserialize

Node* deserialize(const string& data) {
    istringstream iss(data);
    return deserialize(iss);
}//end deserialize wrapper

#endif