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
    void findPaths(TreeNode* root, int targetSum, vector<int> currPath, vector<vector<int>> &allPaths) {

        if(root == NULL) return;
        
        currPath.push_back(root->val);

        if(root->left == NULL && root->right == NULL) {
            if(targetSum - root->val == 0) {
                allPaths.push_back(currPath);
            }
            return;
        }

        findPaths(root->left, targetSum - root->val, currPath, allPaths);
        findPaths(root->right, targetSum - root->val, currPath, allPaths);

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return {};
        vector<vector<int>> allPaths;
        findPaths(root, targetSum, {}, allPaths);
        return allPaths;
    }
};