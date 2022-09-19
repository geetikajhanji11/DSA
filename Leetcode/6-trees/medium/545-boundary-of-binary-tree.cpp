/*******************************************************************
{7,8,9,3,6,#,7,#,#,#,3,8,9}
{37,-34,-48,#,-100,-100,48,#,#,#,#,-54,#,-71,-22,#,#,#,8}
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

    bool isLeaf(TreeNode* root) {
        return root->left == NULL && root->right == NULL;
    }

    void addLeftBoundary(TreeNode* root, vector<int> &result) {
        root = root->left;
        while(root != NULL) {
            if(!isLeaf(root)) result.push_back(root->val);
            if(root->left != NULL) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }

    void addLeaves(TreeNode* root, vector<int> &result) {
        if(root == NULL) return;
        if(isLeaf(root)) {
            result.push_back(root->val);
            return;
        }
        addLeaves(root->left, result);
        addLeaves(root->right, result);
    }

    void addRightBoundary(TreeNode* root, vector<int> &result) {
        root = root->right;
        vector<int> temp;
        while(root != NULL) {
            if(!isLeaf(root)) temp.push_back(root->val);
            if(root->right != NULL) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        for(int i=temp.size()-1; i>=0; i--) {
            result.push_back(temp[i]);
        }
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode *root) {

        if(root == NULL) return {};
        vector<int> result;
        result.push_back(root->val);

        addLeftBoundary(root, result);
        addLeaves(root, result);
        addRightBoundary(root, result);

        return result;
    }
};