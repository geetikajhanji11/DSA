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

    int heightOfTree(TreeNode* root) {
        if(root == NULL) return -1;
        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void dfs(TreeNode* root, int r, int c, vector<vector<string>> &result, int &height) {
        if(root == NULL) return;

        result[r][c] = to_string(root->val);

        dfs(root->left, r+1, c-pow(2,height-r-1), result, height);
        dfs(root->right, r+1, c+pow(2,height-r-1), result, height);
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = heightOfTree(root);
        
        int rows = height + 1;
        int cols = pow(2, height + 1) - 1;
        vector<vector<string>> result(rows, vector<string>(cols, ""));

        dfs(root, 0, (cols-1)/2, result, height);

        return result;

    }
};