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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL) return root;

        // dummy node to avoid edge cases
        TreeNode* dummyRoot = new TreeNode(INT_MAX);
        dummyRoot->left = root;

        // target variables
        TreeNode* targetNode = NULL;
        TreeNode* targetNodeParent = NULL;

        // traverse tree until key is found
        TreeNode* tempParent = dummyRoot;
        TreeNode* tempNode = root;
        bool isLeftChild = true;
        while(tempNode != NULL) {
            if(key < tempNode->val) {
                tempParent = tempNode;
                tempNode = tempNode->left;
                isLeftChild = true;
            } else if(key > tempNode->val) {
                tempParent = tempNode;
                tempNode = tempNode->right;
                isLeftChild = false;
            } else {
                targetNode = tempNode;
                targetNodeParent = tempParent;
                break;
            }
        }

        // key does not exist in tree, no deletion
        if(targetNode == NULL) return dummyRoot->left;
        
        // attach this "adjustedNode" to "targetNodeParent" at the end
        TreeNode* adjustedNode; 
        if(targetNode->left == NULL) {
            adjustedNode = targetNode->right;
        } else if(targetNode->right == NULL) {
            adjustedNode = targetNode->left;
        } else {
            adjustedNode = targetNode->right;
            TreeNode* temp = adjustedNode;
            while(temp->left != NULL) {
                temp = temp->left;
            }
            temp->left = targetNode->left;
        }

        // attach
        if(isLeftChild) {
            targetNodeParent->left = adjustedNode;
        } else {
            targetNodeParent->right = adjustedNode;
        }

        // return root
        return dummyRoot->left;
    }
};