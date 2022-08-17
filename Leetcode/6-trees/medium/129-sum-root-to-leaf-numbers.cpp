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

void dfs(TreeNode* root, int currSum, int &totalSum) {

    if(root == NULL) return;

    currSum = (currSum * 10) + root->val;
    
    // reached a leaf node
    if(root->left == NULL && root->right == NULL) {
        totalSum += currSum;
        return;
    }

    // dfs on both children
    dfs(root->left, currSum, totalSum);
    dfs(root->right, currSum, totalSum);
}


int sumNumbers(TreeNode* root) {
    int totalSum = 0;
    dfs(root, 0, totalSum);
    return totalSum;
}

int main() {

    return 0;
}