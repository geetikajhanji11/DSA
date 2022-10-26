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

    void inorder(TreeNode* root, vector<int> &sorted) {
        if(root == NULL) return;
        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> sorted;
        inorder(root, sorted);

        int left = 0;
        int right = sorted.size() - 1;

        while(left < right) {
            int sum = sorted[left] + sorted[right];
            if(sum == k) return true;

            if(sum < k) {
                left++;
            } else {
                right--;
            }
        }

        return false;
    }
};
