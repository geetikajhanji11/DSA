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

TreeNode* convert(int left, int right, vector<int>& nums) {

    if(left > right) return NULL;

    int mid = (left + right) / 2;

    TreeNode* curr = new TreeNode(nums[mid]);
    curr->left = convert(left, mid-1, nums);
    curr->right = convert(mid+1, right, nums);

    return curr;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = convert(0, nums.size()-1, nums);
    return root;
}

int main() {

    return 0;
}