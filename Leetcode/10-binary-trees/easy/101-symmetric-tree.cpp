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

    // **************** RECURSIVE ****************
    bool isSym(TreeNode* leftNode, TreeNode* rightNode) {
        if(leftNode == NULL && rightNode == NULL) return true;
        if(leftNode == NULL && rightNode != NULL) return false;
        if(leftNode != NULL && rightNode == NULL) return false;
        if(leftNode->val != rightNode->val) return false;

        return isSym(leftNode->left, rightNode->right) && isSym(leftNode->right, rightNode->left); 

    }

    bool isSymmetricRecursive(TreeNode* root) {
        if(root == NULL) return true;
        return isSym(root->left, root->right);
    }

    // **************** ITERATIVE ****************
    bool isSymmetricIterative(TreeNode* root) {
        if(root == NULL) return true;
        
        queue<TreeNode*> leftQueue;
        queue<TreeNode*> rightQueue;

        leftQueue.push(root->left);
        rightQueue.push(root->right);

        while(!leftQueue.empty() && !rightQueue.empty()) {

            TreeNode* leftNode = leftQueue.front(); leftQueue.pop();
            TreeNode* rightNode = rightQueue.front(); rightQueue.pop();

            if(leftNode == NULL && rightNode == NULL) continue;
            if(leftNode == NULL && rightNode != NULL) return false;
            if(leftNode != NULL && rightNode == NULL) return false;

            if(leftNode->val != rightNode->val) return false;

            leftQueue.push(leftNode->left);
            leftQueue.push(leftNode->right);

            rightQueue.push(rightNode->right);
            rightQueue.push(rightNode->left);
        }

        return true;

    }

    bool isSymmetric(TreeNode* root) {
        // return isSymmetricIterative(root);
        return isSymmetricRecursive(root);
    }
};