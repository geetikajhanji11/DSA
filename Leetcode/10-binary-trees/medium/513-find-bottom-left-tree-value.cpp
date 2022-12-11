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

// ************ DFS SOLUTION ************
class Solution {

    void dfs(TreeNode* root, int depth, int &maxDepth, int &leftValue) {
        if(root == NULL) return;
        if(depth > maxDepth) {
            leftValue = root->val;
            maxDepth = depth;
        }

        dfs(root->left, depth+1, maxDepth, leftValue);
        dfs(root->right, depth+1, maxDepth, leftValue);
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = -1;
        int leftValue = 0;
        dfs(root, 0, maxDepth, leftValue);
        return leftValue;
    }
};

// ************ BFS SOLUTION ************
class Solution {

    int bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int result = root->val;

        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            result = curr->val;
            if(curr->right != NULL) q.push(curr->right);
            if(curr->left != NULL) q.push(curr->left);
        }

        return result;
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        return bfs(root);
    }
};