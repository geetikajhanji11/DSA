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

    bool isUnivaluedSubtree(TreeNode* root, int &count) {
        if(root == NULL) return true;

        // leaf node
        if(root->left == NULL && root->right == NULL) {
            count++;
            return true;
        }

        bool left = isUnivaluedSubtree(root->left, count);
        bool right = isUnivaluedSubtree(root->right, count);
        
        if(!left || !right) {
            return false;
        }

        bool currSubtreeIsUnivalued = true;
        if(root->left != NULL && root->left->val != root->val) {
            currSubtreeIsUnivalued = false;
        }  
         if(root->right != NULL && root->right->val != root->val) {
            currSubtreeIsUnivalued = false;
        }  

        if(currSubtreeIsUnivalued) count++;
        
        return currSubtreeIsUnivalued;
    }

public:

    int countUnivalSubtrees(TreeNode *root) {
        if(root == NULL) return 0;

        int count = 0;
        isUnivaluedSubtree(root, count);

        return count;
    }
};