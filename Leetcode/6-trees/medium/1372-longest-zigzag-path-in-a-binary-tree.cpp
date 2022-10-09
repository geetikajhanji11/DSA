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

    // pair => {leftZigzag, rightZigzag}
    pair<int, int> zigzag(TreeNode* root, int &maxLength) {
        if(root == NULL) return {-1, -1};  

        auto leftChildZigzag = zigzag(root->left, maxLength);
        auto rightChildZigzag = zigzag(root->right, maxLength);

        int leftZigzag = 1 + leftChildZigzag.second; // 1 + leftchild's right zigzag 
        int rightZigzag = 1 + rightChildZigzag.first; // 1 + rightchild's left zigzag

        maxLength = max(maxLength, max(leftZigzag, rightZigzag));

        pair<int, int> rootZigzag = {leftZigzag, rightZigzag};
        return rootZigzag;
    }

public:
    int longestZigZag(TreeNode* root) {
        int maxLength = 0;
        zigzag(root, maxLength);
        return maxLength;
    }
};