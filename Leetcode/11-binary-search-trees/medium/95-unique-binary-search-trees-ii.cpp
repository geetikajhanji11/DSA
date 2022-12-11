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

    vector<TreeNode*> generate(int start, int end) {

        // out of bounds
        if(start > end) return {NULL};

        vector<TreeNode*> allTrees;
        for(int val=start; val<=end; val++) {
            
            // left will be from [start, val-1]
            vector<TreeNode*> allLeft = generate(start, val-1);
                
            // right will be from [val+1, end]
            vector<TreeNode*> allRight = generate(val+1, end);

            // create all combinations
            for(TreeNode* leftSubtree : allLeft) {
                for(TreeNode* rightSubtree : allRight) {
                    TreeNode* root = new TreeNode(val);
                    root->left = leftSubtree;
                    root->right = rightSubtree;
                    allTrees.push_back(root);
                } 
            }
        }
         
        return allTrees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};