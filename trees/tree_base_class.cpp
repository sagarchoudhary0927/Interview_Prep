#include <iostream>
#include<vector>

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


void inOrderTraversalList(TreeNode *rootNode, vector<int> &ans) {
  if (rootNode == nullptr) {
    ans.push_back(-1);
    return;
  }
  ans.push_back(rootNode->data);
  // Printing Left Node
  inOrderTraversalList(rootNode->left, ans);
  // Printing Right Node
  inOrderTraversalList(rootNode->right, ans);
}




int main() {
  int input[] = {1, 2, 4, -1, -1, 5, 6, -1, -1, -1, 3, 7, 8, -1, -1, -1, -1};
  TreeNode *tree;
  tree = buildTree();
  cout << endl;
  cout << "Tree is created \n";
  // Inorder Traversal Print
  printTree(tree);

  // Inorder Traversal (Output: Vector / List)
  vector<int> ans;
  inOrderTraversalList(tree, ans);
  cout << endl;
  cout << "--------------------------------" << endl;
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
  cout << "--------------------------------" << endl;
  cout << endl;
  return 0;
}