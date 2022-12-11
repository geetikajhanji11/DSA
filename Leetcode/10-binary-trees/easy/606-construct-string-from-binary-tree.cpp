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

    void preorder(TreeNode* root, string &result) {
        if(root == NULL) return;

        result += to_string(root->val);

        if(root->left != NULL) {
            result += "(";
            preorder(root->left, result);
            result += ")";
        }
        
        if(root->left == NULL && root->right != NULL) {
            result += "()";
        }
        
        if(root->right != NULL) {
            result += "(";
            preorder(root->right, result);
            result += ")";  
        }

    }

public:
    string tree2str(TreeNode* root) {
        string result = "";
        preorder(root, result);
        return result;
    }
};