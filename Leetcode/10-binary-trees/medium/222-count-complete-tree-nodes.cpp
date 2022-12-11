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

    int leftHeightOf(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + leftHeightOf(root->left);
    }

    int rightHeightOf(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + rightHeightOf(root->right);
    }

public:

    int countNodes(TreeNode* root) {
        
        if(root == NULL) return 0;
    
        int leftHeight = leftHeightOf(root);
        int rightHeight = rightHeightOf(root);

        // perfect binary tree
        if(leftHeight == rightHeight) { 
            return pow(2, leftHeight) - 1;
        } 
        
        // complete binary tree
        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);
        return leftNodes + 1 + rightNodes;
        
    }
};