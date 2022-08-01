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

int depth(TreeNode* root) {
    if(root == NULL) return INT_MAX;
    if(root->left == NULL && root->right == NULL) return 1;

    int left_depth = depth(root->left);
    int right_depth = depth(root->right);

    return min(left_depth, right_depth) + 1; 

}

int minDepth(TreeNode* root) {
    if(root == NULL) return 0;
    return depth(root);
}

int main() {

    return 0;
}