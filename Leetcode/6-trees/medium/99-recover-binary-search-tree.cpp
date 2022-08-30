/*******************************************************************
 See Morris Traversal
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

// *********** O(N) SPACE AND TIME NAIVE SOLUTION ***********
// INSIDE INORDER RECURSION ITSELF
class Solution {

    void inorder(TreeNode* root, TreeNode* &prevNode, TreeNode* &badNode1, TreeNode* &badNode2) {
        if(root == NULL) return;
        inorder(root->left, prevNode, badNode1, badNode2);
        
        if(badNode1 == NULL && (prevNode == NULL || prevNode->val >= root->val)) {
            badNode1 = prevNode;
        }

        if(badNode1 != NULL && prevNode->val >= root->val) {
            badNode2 = root;
        }

        prevNode = root;
        inorder(root->right, prevNode, badNode1, badNode2);
    }

public:
    void recoverTree(TreeNode* root) {
        
        TreeNode* prevNode = NULL;
        TreeNode* badNode1 = NULL;
        TreeNode* badNode2 = NULL;

        inorder(root, prevNode, badNode1, badNode2);

        int temp = badNode1->val;
        badNode1->val = badNode2->val;
        badNode2->val = temp;

    }
};


// *********** O(N) SPACE AND TIME NAIVE SOLUTION ***********
// CREATING SEPARATE ARRAY
class Solution {

    void inorder(TreeNode* root, vector<TreeNode*> &result) {
        if(root == NULL) return;
        inorder(root->left, result);
        result.push_back(root);
        inorder(root->right, result);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> result;
        inorder(root, result);

        int idx1 = -1;
        int idx2 = -1;

        for(int i=0; i<result.size()-1; i++) {
            if(result[i]->val >= result[i+1]->val) {
                if(idx1 == -1) {
                    idx1 = i;
                } else {
                    idx2 = i+1;
                    break;
                }
            }
        }

        if(idx2 == -1) {
            idx2 = idx1 + 1;
        }

        int temp = result[idx1]->val;
        result[idx1]->val = result[idx2]->val;
        result[idx2]->val = temp; 

    }
};