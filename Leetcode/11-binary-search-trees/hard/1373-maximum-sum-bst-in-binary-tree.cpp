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

class Info {
public:
    bool isBST;
    int sum;
    int minVal;
    int maxVal;

    Info(int isBST, int sum, int minVal, int maxVal) {
        this->isBST = isBST;
        this->sum = sum;
        this->minVal = minVal;
        this->maxVal = maxVal;
    }
 
};

class Solution {

    Info isBSTandSum(TreeNode* root, int &result) {
        if(root == NULL) return Info(true, 0, INT_MAX, INT_MIN);

        // logic
        auto left = isBSTandSum(root->left, result);
        auto right = isBSTandSum(root->right, result);

        // not bst cases
        if(!left.isBST || !right.isBST) { 
            return Info(false, 0, INT_MIN, INT_MAX);
        }
        if(left.maxVal >= root->val || right.minVal <= root->val) {
            return Info(false, 0, INT_MAX, INT_MIN);
        }

        // is a bst
        int newSum = left.sum + root->val + right.sum;
        result = max(result, newSum);
        
        // for new bst
        int newMinVal = min(left.minVal, root->val);
        int newMaxVal = max(right.maxVal, root->val);

        return Info(true, newSum, newMinVal, newMaxVal);

    }

public:
    int maxSumBST(TreeNode* root) {
        int result = INT_MIN;
        isBSTandSum(root, result);

        if(result < 0) return 0;
        return result;
    }
};