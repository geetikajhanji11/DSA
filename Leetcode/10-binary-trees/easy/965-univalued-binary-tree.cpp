/*******************************************************************

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

    bool isUnival(TreeNode* root, int &val) {
        if(root == NULL) return true;
        if(root->val != val) return false;
        return isUnival(root->left, val) && isUnival(root->right, val);
    }

public:
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        return isUnival(root, val);
    }
};