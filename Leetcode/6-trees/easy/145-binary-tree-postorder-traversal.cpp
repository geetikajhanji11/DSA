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

void postorder(TreeNode* root, vector<int> &result) {
    if(root == NULL) return;
    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    postorder(root, result);
    return result; 
}

int main() {

    return 0;
}