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

    bool hasSum(TreeNode* root, int targetSum) {

        if(root == NULL) return false;
        
        if(root->left == NULL && root->right == NULL) {
            return targetSum - root->val == 0;
        }

        bool ifLeftSum = hasSum(root->left, targetSum - root->val);
        bool ifRightSum = hasSum(root->right, targetSum - root->val);

        return ifLeftSum || ifRightSum;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return hasSum(root, targetSum);
    }
};