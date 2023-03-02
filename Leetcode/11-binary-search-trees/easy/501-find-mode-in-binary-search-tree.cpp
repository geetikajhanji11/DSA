/*******************************************************************
Can be done with 2 passes. (better)

1st pass => get the maxfreq of any number
2nd pass => get all numbers with maxfreq
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

    void inorder(TreeNode* root, int &prev, int &prevCount, int &maxFreq, vector<int> &result) {
       if(root == NULL) return;

        // LEFT
        inorder(root->left, prev, prevCount, maxFreq, result);

        // work on current val
        int currCount = 1;
        if(root->val == prev) {
            currCount += prevCount;
        }

        if(currCount > maxFreq) {
            maxFreq = currCount;
            result.clear();
        }

        if(currCount == maxFreq) {
            result.push_back(root->val);
        }

        prev = root->val;
        prevCount = currCount;

        // RIGHT
        inorder(root->right, prev, prevCount, maxFreq, result);

    }

public:
    vector<int> findMode(TreeNode* root) {
        int maxFreq = 0;
        vector<int> result;
        int prev = INT_MAX;
        int prevCount = 0;

        inorder(root, prev, prevCount, maxFreq, result);

        return result;
    }
};