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

// first => HEAD
// second => TAIL
pair<TreeNode*, TreeNode*> getLinkedListHeadAndTail(TreeNode* root) {

    if(root == NULL) return {NULL, NULL};

    // CASE 1: LEAF NODE
    if(root->left == NULL && root->right == NULL) return {root, root};

    // CASE 2: BOTH LEFT AND RIGHT SUBTREE EXIST
    if(root->left != NULL && root->right != NULL) {
        auto left_LL = getLinkedListHeadAndTail(root->left);
        auto right_LL = getLinkedListHeadAndTail(root->right);
        root->right = left_LL.first; 
        left_LL.second->right = right_LL.first; 
        root->left = NULL; // left child pointer is always null.
        return {root, right_LL.second};
    }

    // CASE 3: ONLY LEFT SUBTREE EXISTS
    else if(root->left != NULL && root->right == NULL) {
        auto left_LL = getLinkedListHeadAndTail(root->left);
        root->right = left_LL.first;
        root->left = NULL; // left child pointer is always null.
        return {root, left_LL.second};
    }

    // CASE 4: ONLY RIGHT SUBTREE EXISTS
    else if(root->left == NULL && root->right != NULL) {
        auto right_LL = getLinkedListHeadAndTail(root->right);
        root->right = right_LL.first;
        root->left = NULL; // left child pointer is always null.
        return {root, right_LL.second};
    }

    return {root, root};
}

void flatten(TreeNode* root) {
    getLinkedListHeadAndTail(root);
}

int main() {

    return 0;
}