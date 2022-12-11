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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL) return 0;
        
        int maxWidth = 0;

        // node, index
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while(!q.empty()) {

            int minIndex = q.front().second; // avoid overflow

            int firstIndex = 0;
            int lastIndex = 0;

            int size = q.size();

            for(int i=0; i<size; i++) {

                TreeNode* currNode = q.front().first;
                int currIndex = q.front().second - minIndex;
                q.pop();

                if(i == 0) firstIndex = currIndex;
                if(i == size - 1) lastIndex = currIndex;

                if(currNode->left != NULL) q.push({currNode->left, (long long)currIndex * 2 + 1});
                if(currNode->right != NULL) q.push({currNode->right, (long long)currIndex * 2 + 2});

            }
            maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
        }

        return maxWidth;
    }
};