/*******************************************************************
{1,#,3,4,5,6,7,8,9,10,11,13,#,#,#,12,20,14}

{1,2,3,4,5,6,7,8,9,10,11,13,#,#,#,12,20,14}
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
    TreeNode* upsideDownBinaryTree(TreeNode *root) {
        if(!root) return root;
        if(!root->left) return root;

        TreeNode* parent = root; 
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = NULL;
        root->right = NULL;

        while(true) {

            if(!left) return parent;

            TreeNode* l = left->left;
            TreeNode* r = left->right;
            
            left->right = parent;
            left->left = right;

            parent = left;
            left = l;
            right = r;
        }

        return root;
    }
};