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

// ********** SAME SOLUTION, USE HASHING **********
class Solution {

    TreeNode* build(int inLeft, int inRight, vector<int> &inorder, int postLeft, int postRight, vector<int> &postorder, unordered_map<int, int> &inorderMap) {
        
        // empty array
        if(inRight - inLeft + 1 <= 0) return NULL;

        int rootVal = postorder[postRight];
        TreeNode* root = new TreeNode(rootVal);

        // iterate over inorder to find out 
        // elements that come before rootVal
        int i = inorderMap[rootVal];
        
        // size of the new inorder and postorder arrays
        int size = (i - 1) - inLeft + 1;

        // i is at rootVal in inorder array currently
        root->left = build(inLeft, i-1, inorder, postLeft, postLeft + size - 1, postorder, inorderMap);
        root->right = build(i+1, inRight, inorder, postLeft + size, postRight-1, postorder, inorderMap);

        return root;
    }


public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> inorderMap;
        for(int i=0; i<n; i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(0, n-1, inorder, 0, n-1, postorder, inorderMap);
    }
};

// ********** SAME SOLUTION, BUT USING INDEXES INSTEAD OF CREATING ARRAY **********
class Solution {

    TreeNode* build(int inLeft, int inRight, vector<int> &inorder, int postLeft, int postRight, vector<int> &postorder) {
        
        // empty array
        if(inRight - inLeft + 1 <= 0) return NULL;

        int rootVal = postorder[postRight];
        TreeNode* root = new TreeNode(rootVal);

        // iterate over inorder to find out 
        // elements that come before rootVal
        int i = inLeft;
        while(i <= inRight && inorder[i] != rootVal) {
            i++;
        }
        
        // size of the new inorder and postorder arrays
        int size = (i - 1) - inLeft + 1;

        // i is at rootVal in inorder array currently
        root->left = build(inLeft, i-1, inorder, postLeft, postLeft + size - 1, postorder);
        root->right = build(i+1, inRight, inorder, postLeft + size, postRight-1, postorder);

        return root;
    }


public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(0, n-1, inorder, 0, n-1, postorder);
    }
};


// ********** SAME SOLUTION, BUT CREATING NEW ARRAY **********
class Solution {

    TreeNode* build(vector<int> inorder, vector<int> postorder) {
        int n = inorder.size();
        if(n == 0) return NULL;

        int rootVal = postorder[n - 1];

        TreeNode* root = new TreeNode(rootVal);

        // iterate over inorder to find out 
        // elements that come before rootVal
        int i = 0;
        vector<int> leftInorder;
        while(i < n && inorder[i] != rootVal) {
            leftInorder.push_back(inorder[i]);
            i++;
        }

        // i is at rootVal
        i++;
        vector<int> rightInorder;
        while(i < n) {
            rightInorder.push_back(inorder[i]);
            i++;
        }


        // find new post order for left and right
        int leftSize = leftInorder.size();
        int rightSize = rightInorder.size();

        vector<int> leftPostorder;
        vector<int> rightPostorder;

        i = 0;
        while(i < leftSize) {
            leftPostorder.push_back(postorder[i]);
            i++;
        }

        while(i < n - 1) {
            rightPostorder.push_back(postorder[i]);
            i++;
        }

        root->left = build(leftInorder, leftPostorder);
        root->right = build(rightInorder, rightPostorder);

        return root;
    }


public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder);
    }
};