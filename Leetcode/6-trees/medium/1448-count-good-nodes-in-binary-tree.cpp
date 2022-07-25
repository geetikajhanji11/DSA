/*******************************************************************
Given binary tree, node is "good" if path from root has no nodes > X, 
return # of "good"

Maintain greatest value seen so far on a path, 
if further node >= this max, "good" node

Time: O(n)
Space: O(n)
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

void countGoodNodes(TreeNode* root, int m, int &ctr) {
    if(root == NULL) return;

    if(root->val >= m) ctr++;

    int next_m = max(m, root->val);
    countGoodNodes(root->left, next_m, ctr);
    countGoodNodes(root->right, next_m, ctr);
}

int countGoodNodes(TreeNode* root, int m) {
    if(root == NULL) return 0;

    int goodNodes = 0;
    if(root->val >= m) goodNodes = 1; 

    int next_m = max(m, root->val);
    goodNodes += countGoodNodes(root->left, next_m);
    goodNodes +=  countGoodNodes(root->right, next_m);

    return goodNodes;
}

int goodNodes(TreeNode* root) {
    int ctr = 0;
    countGoodNodes(root, INT_MIN, ctr);
    return ctr;
}

int main() {

    return 0;
}