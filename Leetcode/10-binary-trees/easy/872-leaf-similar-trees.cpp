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

    void dfs(TreeNode *root, vector<int> &leafNodes) {
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL) {
            leafNodes.push_back(root->val);
        }

        dfs(root->left, leafNodes);
        dfs(root->right, leafNodes);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leafNodes1;
        dfs(root1, leafNodes1);

        vector<int> leafNodes2;
        dfs(root2, leafNodes2);

        if(leafNodes1.size() != leafNodes2.size()) return false;

        for(int i=0; i<leafNodes1.size(); i++) {
            if(leafNodes1[i] != leafNodes2[i]) return false;
        }

        return true;
    }
};