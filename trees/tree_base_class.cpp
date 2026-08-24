#include <iostream>
#include "tree_node.h"
using namespace std;

// Input = 1 2 4 -1 -1 5 6 -1 -1 -1 3 7 8 -1 -1 -1 -1


TreeNode *buildTree() {
  // Taking Inputs
  int input;
  cin >> input;

  // Node is null
  if (input == -1) {
    return nullptr;
  }

  TreeNode *n = new TreeNode(input);  
  n->left = buildTree(); // Left Tree
  n->right = buildTree(); // Right Tree
  return n;
}

void printTree(TreeNode *rootNode) {
  if (rootNode == nullptr) {
    return;
  }
  cout << rootNode->data << " ";
  // Printing Left Node
  printTree(rootNode->left);
  // Printing Right Node
  printTree(rootNode->right);
}




int main() {
  int input[] = {1, 2, 4, -1, -1, 5, 6, -1, -1, -1, 3, 7, 8, -1, -1, -1, -1};
  TreeNode *tree;
  tree = buildTree();
  cout << endl;
  cout << "Tree is created \n";
  printTree(tree);
  cout << endl;
  return 0;
}