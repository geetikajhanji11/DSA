/*******************************************************************
TreeNode* pruneTree(TreeNode* root) {
    if (!root) return NULL;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (!root->left && !root->right && root->val == 0) return NULL;
    return root;
}
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    bool canBePruned(TreeNode* root) {
        if(root == NULL) return true;

        bool leftCanBePruned = canBePruned(root->left);
        bool rightCanBePruned = canBePruned(root->right);

        if(leftCanBePruned) root->left = NULL;
        if(rightCanBePruned) root->right = NULL;

        return leftCanBePruned && rightCanBePruned && (root->val != 1);
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        if(canBePruned(root)) return NULL;
        return root;
    }
};