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

// ********** MY SOLUTION **********
class Solution {

    // {start node of IBST, end node of IBST}
    // {head, tail}
    pair<TreeNode*, TreeNode*> getIncreasingBST(TreeNode* root) {
        
        // null node
        if(root == NULL) return {NULL, NULL};

        // leaf node
        if(root->left == NULL && root->right == NULL) {
            return {root, root};
        }

        // normal node
        auto left = getIncreasingBST(root->left);
        auto right = getIncreasingBST(root->right);

        // return {head, tail} of this IBST
        pair<TreeNode*, TreeNode*> p;

        // if the left subtree existed
        if(left.second != NULL) {
            // the "right" of the tail of the
            // left subtree will now be "root"
            (left.second)->right = root;
            p.first = left.first; 
        } else {
            p.first = root;
        }

        // if the right subtree existed
        if(right.first != NULL) {
            // the "right" of root will be the
            // head of right subtree
            root->right = right.first;
            p.second = right.second;
        } else {
            p.second = root;
        }

        // make root->left = NULL
        root->left = NULL;

        return p;
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        auto p = getIncreasingBST(root);
        return p.first;
    }
};