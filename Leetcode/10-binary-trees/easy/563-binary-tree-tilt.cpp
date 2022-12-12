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

    int subtreeSum(TreeNode* root, int &tiltSum) {
        if(root == NULL) return 0;

        int leftSubtreeSum = subtreeSum(root->left, tiltSum);
        int rightSubtreeSum = subtreeSum(root->right, tiltSum);

        int rootSubtreeSum = root->val + leftSubtreeSum + rightSubtreeSum;
        
        int rootTilt = abs(leftSubtreeSum - rightSubtreeSum);
        tiltSum += rootTilt;

        return rootSubtreeSum;
    }

public:
    int findTilt(TreeNode* root) {
        int tiltSum = 0;
        subtreeSum(root, tiltSum);
        return tiltSum;
    }
};