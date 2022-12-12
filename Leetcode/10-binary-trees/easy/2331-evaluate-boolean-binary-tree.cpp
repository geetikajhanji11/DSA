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
public:
    bool evaluateTree(TreeNode* root) {

        // leaf node
        if(root->left == NULL && root->right == NULL) {
            return root->val;
        }

        // non leaf node
        bool leftVal = evaluateTree(root->left);
        bool rightVal = evaluateTree(root->right);

        if(root->val == 2) return leftVal || rightVal;
        return leftVal && rightVal; 
    }
};