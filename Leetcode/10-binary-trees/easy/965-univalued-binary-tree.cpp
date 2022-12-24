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

    bool isUnival(TreeNode* root, int &val) {
        if(root == NULL) return true;
        if(root->val != val) return false;
        return isUnival(root->left, val) && isUnival(root->right, val);
    }

public:
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        return isUnival(root, val);
    }
};

// ************ OTHER SOLUTION ************
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        
        bool flag = true;
        if(root->left) {
            flag = flag && isUnivalTree(root->left);
            flag = flag && (root->val == root->left->val);
        }

        if(root->right) {
            flag = flag && isUnivalTree(root->right);
            flag = flag && (root->val == root->right->val);
        }

        return flag;
    }
};
