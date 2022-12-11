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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;

        q.push(root);
        int level = 0;
        
        int maxLevel = 0;
        int maxLevelSum = INT_MIN;

        while(!q.empty()) {

            level++;

            int size = q.size();
            int currLevelSum = 0;

            while(size != 0) {
                TreeNode* curr = q.front(); q.pop();
                currLevelSum += curr->val;

                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);

                size--;
            }

            if(currLevelSum > maxLevelSum) {
                maxLevelSum = currLevelSum;
                maxLevel = level;
            }

        }

        return maxLevel;

    }
};