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

    vector<TreeNode*> fullBTs(int n) {

        if(n == 0) return {NULL};
        if(n == 1) return {new TreeNode(0)};

        vector<TreeNode*> result;

        // each root has to have n value as odd
        // root takes 1 node, rest (n-1) even nodes are children
        // this loop runs for all odd numbers in range [1, n)
        // not including n since it itself is odd and if we include it, 
        // we will have no right subtree
        for(int i=1; i<n; i=i+2) {

            vector<TreeNode*> leftFullBTs = fullBTs(i);
            vector<TreeNode*> rightFullBTs = fullBTs(n-i-1);
            
            for(TreeNode* left : leftFullBTs) {
                for(TreeNode* right : rightFullBTs) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return {};

        return fullBTs(n);
    }
};