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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(!root) return root;
        
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int currDepth = 1;
        queue<TreeNode*> q;
        q.push(root);
        
        while(currDepth < depth - 1) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front(); q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            currDepth++;    
        }

        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();

            TreeNode* nodeLeft = new TreeNode(val);
            TreeNode* nodeRight = new TreeNode(val);

            nodeLeft->left = curr->left;
            nodeRight->right = curr->right;

            curr->left = nodeLeft;
            curr->right = nodeRight;
        }

        return root;
    }
};