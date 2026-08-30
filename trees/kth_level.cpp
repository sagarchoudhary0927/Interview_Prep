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

vector<int> kthLevel(int level, TreeNode * root) {
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    int currLevel = 0;

    while (!q.empty()) {
        TreeNode *temp = q.front();
        if (temp == nullptr) {
            currLevel = currLevel + 1;
            q.pop();
            if(!q.empty()) {
                q.push(nullptr);
            }
        }
        else
        {
            if (currLevel == level) {
                ans.push_back(temp->data);
            }
            q.pop();
            if(temp->left != nullptr) {
                q.push(temp->left);
            }

            if(temp->right != nullptr) {
                q.push(temp->right);
            }
        }
    }

    return ans;
}

// INPUT :- 50 60 70 90 40 40 20 -1 -1 -1 -1 -1 -1 -1 -1
int main() {
    TreeNode *tree = buildLevelOrderTree();
    vector<int> ans = kthLevel(1, tree);
    cout << endl;
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}