/*******************************************************************
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        for (int num : nums) {
            TreeNode* node = new TreeNode(num);
            while (!stk.empty() && stk.top() -> val < node -> val) {
                node -> left = stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                stk.top() -> right = node;
            }
            stk.push(node);
        }
        while (stk.size() > 1) {
            stk.pop();
        }
        return stk.top();
    }
};
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

// ************** RECURSIVE SOLUTION **************
// O(N^2)
class Solution {

    TreeNode* construct(int i, int j, vector<int>& nums) {
        if(i > j) return NULL;
        if(i == j) return new TreeNode(nums[i]);

        int maxNumber = INT_MIN;
        int maxNumberIdx = i;
        for(int k=i; k<=j; k++) {
            if(nums[k] > maxNumber) {
                maxNumber = nums[k];
                maxNumberIdx = k;
            }
        }

        TreeNode* root = new TreeNode(maxNumber);
        root->left = construct(i, maxNumberIdx-1, nums);
        root->right = construct(maxNumberIdx+1, j, nums);

        return root;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(0, nums.size()-1, nums);
    }
};

// ************** STACK SOLUTION **************
// MONOTONICALLY DECREASING STACK
// O(N)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> s;

        for(int num : nums) {
            TreeNode* currNode = new TreeNode(num);
            
            while(!s.empty() && currNode->val > s.top()->val) {
                currNode->left = s.top();
                s.pop();
            }

            if(!s.empty()) {
                s.top()->right = currNode;
            }

            s.push(currNode);
        }      

        while(s.size() > 1) s.pop();

        return s.top();
    }
};