#include <iostream>
#include<queue>
#include "tree_node.h"
using namespace std;


// 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1


TreeNode * buildLevelOrderTree() {
    int rootData;
    cin >> rootData;

    if(rootData == -1) {
        return nullptr;
    }

    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *current = q.front();
        q.pop();

        int c1, c2;
        cin >> c1;
        cin >> c2;
        if(c1 != -1) {
            current->left = new TreeNode(c1);
            q.push(current->left);
        }
        else {
            current->left = nullptr;
        }

        if(c2 != -1) {
            current->right = new TreeNode(c2);
            q.push(current->right);
        }
        else {
            current->right = nullptr;
        }
    }

    return root;
}

int heightOfTree(TreeNode * root) {
    queue<TreeNode *> q;
    if (root == nullptr) {
        return 0;
    }
    q.push(root);
    q.push(nullptr);
    int height = 0;
    cout << endl;
    cout << "Calculating height for node = " << root->data << endl;

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        if (temp == nullptr) {
            q.pop();
            height = height + 1;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            q.pop();
            if(temp->left != nullptr) {
                q.push(temp->left);
            }
            if(temp->right != nullptr) {
                q.push(temp->right);
            }
        }
    }
    return height;
}


// INPUT :- 50 60 70 90 40 40 20 -1 -1 -1 -1 -1 -1 -1 -1
int main() {
    TreeNode *tree = buildLevelOrderTree();
    cout << endl;
    return 0;
}