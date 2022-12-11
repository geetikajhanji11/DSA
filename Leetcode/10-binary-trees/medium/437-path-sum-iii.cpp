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


// ********* DISCUSS SOLUTION ********* 
// Time: O(N)
// Space: O(N)
class Solution {

    void noOfPathSums(TreeNode* root, long currPathSum, int &target, unordered_map<long, int> m, int &ctr) {
        if(root == NULL) return;

        currPathSum += root->val;
        if(currPathSum == target) ctr++;

        long oldPathSum = currPathSum - target;
        if(m.find(oldPathSum) != m.end()) {
            ctr += m[oldPathSum];
        }
        m[currPathSum]++;

        noOfPathSums(root->left, currPathSum, target, m, ctr);
        noOfPathSums(root->right, currPathSum, target, m, ctr);

        m[currPathSum]--;

    }


public:
    int pathSum(TreeNode* root, int targetSum) {

        unordered_map<long, int> m;
        int ctr = 0;
        noOfPathSums(root, 0, targetSum, m, ctr);
        return ctr;
    }
};

// ********* MY SOLUTION ********* 
class Solution {

    int noOfPathSums(TreeNode* root, vector<long long> prevSums, int &target) {
        if(root == NULL) return 0;

        int ctr = 0;

        for(int i=0; i<prevSums.size(); i++) {
            prevSums[i] += root->val;
            if(prevSums[i] == target) ctr++;
        }

        prevSums.push_back(root->val);
        if(root->val == target) ctr++;

        ctr += noOfPathSums(root->left, prevSums, target);
        ctr += noOfPathSums(root->right, prevSums, target);

        return ctr;
    }


public:
    int pathSum(TreeNode* root, int targetSum) {
        return noOfPathSums(root, {}, targetSum);
    }
};