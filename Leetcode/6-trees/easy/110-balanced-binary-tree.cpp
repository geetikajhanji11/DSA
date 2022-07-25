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

// first -> height of root
// second -> if root is balanced or not
pair<int, bool> getHeightAndIsBalanced(TreeNode* root) {

    if(root == 0) return {-1, true};

    auto left = getHeightAndIsBalanced(root->left);
    auto right = getHeightAndIsBalanced(root->right);
    int curr_height = 1 + max(left.first, right.first);

    // if any of the children is not balanced, return false
    if(!left.second || !right.second) return {curr_height, false}; 
    int diff = abs(left.first - right.first);
    if(diff > 1) { // parent is not balanced
        return {curr_height, false};
    }   

    // if passed all, return true
    return {curr_height, true};
}


bool isBalanced(TreeNode* root) {
    return getHeightAndIsBalanced(root).second;
}

