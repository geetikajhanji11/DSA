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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        TreeNode* temp = root;

        while(temp != NULL) {

            // goes right
            if(val > temp->val) {
                if(temp->right == NULL) {
                    temp-> right = new TreeNode(val);
                    return root;
                } else temp = temp->right;
            }

            // goes left
            else {
                if(temp->left == NULL) {
                    temp-> left = new TreeNode(val);
                    return root;
                } else temp = temp->left;
            }


        }

        return root;
    }
};