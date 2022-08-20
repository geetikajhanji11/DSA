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

void dfs(TreeNode* root, string curr, vector<string> &result) {
    if(root == NULL) return;

    curr += to_string(root->val);
    if(root->left == NULL && root->right == NULL) {
        result.push_back(curr);
        return;
    }
    curr += "->";

    dfs(root->left, curr, result);
    dfs(root->right, curr, result);

}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;     
    dfs(root, "", result);
    return result;   
}

int main() {

    return 0;
}