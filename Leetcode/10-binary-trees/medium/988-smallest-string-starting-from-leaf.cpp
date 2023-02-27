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

    void findPaths(TreeNode* root, string curr, string &smallest) {
        if(root == NULL) return;

        char letter = root->val + 'a';
        curr = curr + letter;
        
        // leafnode
        if(root->left == NULL && root->right == NULL) {
            reverse(curr.begin(), curr.end());
            if(smallest == "" || curr < smallest) smallest = curr;
            return;
        }

        findPaths(root->left, curr, smallest);
        findPaths(root->right, curr, smallest);
    }


public:
    string smallestFromLeaf(TreeNode* root) {
        string smallest = "";

        findPaths(root, "", smallest);

        return smallest;
    }
};