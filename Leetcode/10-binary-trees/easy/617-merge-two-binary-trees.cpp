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

// using the original tree reference
TreeNode* merge(TreeNode* root1, TreeNode* root2) {

    if(root1 == NULL && root2 == NULL) return NULL;
    if(root1 == NULL && root2 != NULL) return root2;
    if(root1 != NULL && root2 == NULL) return root1;

    TreeNode* root = new TreeNode(root1->val + root2->val);
    root->left = merge(root1->left, root2->left);
    root->right = merge(root1->right, root2->right);

    return root;

}

// creating brand new tree altogether
TreeNode* merge(TreeNode* root1, TreeNode* root2) {

    if(root1 == NULL && root2 == NULL) return NULL;
    
    int val1 = root1 == NULL ? 0 : root1->val;
    int val2 = root2 == NULL ? 0 : root2->val;

    TreeNode* root = new TreeNode(val1 + val2);

    root->left = merge(root1 == NULL ? NULL : root1->left, root2 == NULL ? NULL : root2->left);
    root->right = merge(root1 == NULL ? NULL : root1->right, root2 == NULL ? NULL : root2->right);

    return root;

}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    return merge(root1, root2);
}

int main() {

    return 0;
}