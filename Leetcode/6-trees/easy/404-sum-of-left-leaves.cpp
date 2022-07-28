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

int sum_of_left(TreeNode* root, bool is_left) {
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL && is_left) 
        return root->val;

    int left_sum = sum_of_left(root->left, true);
    int right_sum = sum_of_left(root->right, false);

    return left_sum + right_sum;
}

int sumOfLeftLeaves(TreeNode* root) {
    int left = sum_of_left(root->left, true);
    int right = sum_of_left(root->right, false);
    return left + right;
}

int main() {

    return 0;
}