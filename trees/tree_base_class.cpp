#include <iostream>
#include<vector>
#include<queue>

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


void preOrderTraversalList(TreeNode *rootNode, vector<int> &ans) {
  if (rootNode == nullptr) {
    ans.push_back(-1);
    return;
  }
  ans.push_back(rootNode->data);
  // Printing Left Node
  preOrderTraversalList(rootNode->left, ans);
  // Printing Right Node
  preOrderTraversalList(rootNode->right, ans);
}

void inOrderTraversal(TreeNode *rootNode) {
  if (rootNode == nullptr) {
    return;
  }
  //Traversing Left Child First
  inOrderTraversal(rootNode->left);
  // Action with Parent
  cout << rootNode->data << " ";
  // Traversing Right
  inOrderTraversal(rootNode->right);
}

void levelOrderTraversal(TreeNode *root) {
  queue<TreeNode *> list;
  list.push(root);
  list.push(nullptr);

  while (!list.empty()) {
    TreeNode *temp = list.front();
    if (temp == nullptr) {
      cout << endl;
      list.pop();
      if(!list.empty()) {
        list.push(nullptr);
      }
    } else {
      list.pop();
      cout << temp->data << " ";
      if (temp->left)
      {
        list.push(temp->left);
      }
      if(temp->right) 
      {
        list.push(temp->right);
      }
    }
  }
}




int main() {
  int input[] = {1, 2, 4, -1, -1, 5, 6, -1, -1, -1, 3, 7, 8, -1, -1, -1, -1};
  TreeNode *tree;
  tree = buildTree();
  cout << endl;
  cout << "Tree is created \n";
  // Inorder Traversal Print
  printTree(tree);

  // PreOrderTraversalList Traversal (Output: Vector / List)
  vector<int> ans;
  preOrderTraversalList(tree, ans);
  cout << endl;
  cout << "--------------------------------" << endl;
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
  cout << "--------------------------------" << endl;
  cout << endl;

  cout << "--------------------------------" << endl;
  cout << endl;
  cout << "Printing In Order Traversal" << endl;
  inOrderTraversal(tree);
  cout << endl;
  cout << "--------------------------------" << endl;
  cout << endl;

  cout << "Now printing level order traversal" << endl;
  levelOrderTraversal(tree);
  cout << endl;
  return 0;
}