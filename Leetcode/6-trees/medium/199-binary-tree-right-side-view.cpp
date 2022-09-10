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

// ********** DFS SOLUTION **********
class Solution {
    void dfs(TreeNode* root, int depth, vector<int> &result) {
        if(root == NULL) return;

        if(result.size() == depth) {
            result.push_back(root->val);
        }

        dfs(root->right, depth+1, result);
        dfs(root->left, depth+1, result);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
};

// ********** BFS SOLUTION **********
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        
        while(!q.empty()) {

            int size = q.size();
            if(size == 0) break; 

            TreeNode* curr = NULL;
            while(size != 0) {
                curr = q.front();
                q.pop();

                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);

                size--;
            }

            result.push_back(curr->val);
        }
        return result;
    }
};
