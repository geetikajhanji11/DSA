/*******************************************************************
REALLY LIKE THIS QUESTION
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

    void reverseInorder(TreeNode* root, int &currSum) {
        if(root == NULL) return;

        reverseInorder(root->right, currSum);
        currSum += root->val;
        root->val = currSum;
        reverseInorder(root->left, currSum);
    }


    // Reverse Inorder Traversal
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return NULL;
        int currSum = 0;
        reverseInorder(root, currSum);
        return root;
    }
};