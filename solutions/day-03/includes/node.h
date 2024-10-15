// HEADER FILE: node.h

#ifndef H_NODE
#define H_NODE 

#include <string>
using namespace std;

class Node {
  public:
    string info;
    Node* left;
    Node* right;

      // constructor
    Node(const string& value, Node* leftChild = nullptr, Node* rightChild = nullptr)
        : info(value), left(leftChild), right(rightChild) {}

      // deconstructor
    ~Node() {
      delete left;
      delete right;
    }
};

#endif