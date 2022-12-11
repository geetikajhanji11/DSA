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

    TreeNode* construct(int pre_i, int pre_j, vector<int>& preorder, int post_i, int post_j, vector<int>& postorder) {
        if(pre_i > pre_j) return NULL;
        if(pre_i == pre_j) return new TreeNode(preorder[pre_i]);

        TreeNode* root = new TreeNode(preorder[pre_i]);

        // range for postorder cut
        // left_postorder = [post_i, l]
        // right_postorder = [l+1, post_j-1]
        int l;
        for(l=post_i; l<=post_j; l++) {
            if(postorder[l] == preorder[pre_i + 1]) {
                break;
            }
        }

        // range for preorder cut
        // left_preorder = [pre_i+1, k]
        // right_preorder = [k+1, pre_j]
        int k = (pre_i + 1) + (l - post_i);
    
        root->left = construct(pre_i+1, k, preorder, post_i, l, postorder);
        root->right = construct(k+1, pre_j, preorder, l+1, post_j-1, postorder);

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return construct(0, n-1, preorder, 0, n-1, postorder);
    }
};