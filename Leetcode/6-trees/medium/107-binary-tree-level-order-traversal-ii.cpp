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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    
    if(root == NULL) return {};

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    vector<vector<int>> result;

    vector<int> level_nodes;

    while(!q.empty()) {

        TreeNode* curr = q.front();
        q.pop();

        if(curr == NULL) {
            result.push_back(level_nodes);
            if(q.empty()) break;
            level_nodes.clear();
            q.push(NULL);
            continue;
        }

        level_nodes.push_back(curr->val);
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }   

    reverse(result.begin(), result.end());
    return result;     
}

int main() {

    return 0;
}