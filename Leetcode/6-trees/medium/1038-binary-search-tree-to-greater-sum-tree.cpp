/*******************************************************************
EXACTLY SAME AS 538: https://leetcode.com/problems/convert-bst-to-greater-tree/
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

    // right, data, left
    void inorder(TreeNode* root, int &sum) {
        if(root == NULL) return;
        
        inorder(root->right, sum);
        
        root->val += sum;
        sum = root->val;
        
        inorder(root->left, sum);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        inorder(root, sum);
        return root;
    }
};