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

void dfs(TreeNode* root, vector<int> &result) {
    if(root == NULL) return;

    dfs(root->left, result);
    result.push_back(root->val);
    dfs(root->right, result);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    dfs(root, result);
    return result;
}

int main() {

    return 0;
}