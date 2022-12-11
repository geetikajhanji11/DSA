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

    TreeNode* preorderTraversal(int &i, int leftRange, int rightRange, vector<int>& preorder) {

        // array is finished
        if(i == preorder.size()) return NULL;

        // not the correct range
        if(preorder[i] <= leftRange || preorder[i] >= rightRange) return NULL;

        int val = preorder[i];
        i++;

        TreeNode* root = new TreeNode(val);

        root->left = preorderTraversal(i, leftRange, val, preorder);
        root->right = preorderTraversal(i, val, rightRange, preorder);

        return root;
    }


public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return preorderTraversal(i, INT_MIN, INT_MAX, preorder);
    }
};