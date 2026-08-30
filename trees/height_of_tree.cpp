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

void printLevelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {
        TreeNode *temp = q.front();
        if (temp == nullptr) {
            q.pop();
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
}

int heightOfTree(TreeNode * root) {
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    int height = 0;

    while(!q.empty()) {
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

int main() {
    TreeNode *tree = buildLevelOrderTree();
    // printLevelOrder(tree);
    // cout << endl;
    cout << "Height of tree = " << heightOfTree(tree);
    return 0;
}