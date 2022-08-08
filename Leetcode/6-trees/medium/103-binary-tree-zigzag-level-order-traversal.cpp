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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root == NULL) return {};

    queue<TreeNode*> q;
    q.push(root);

    bool forwards = true;

    vector<vector<int>> result;

    while(!q.empty()) {
        vector<int> temp;
        int level_size = q.size();

        while(level_size != 0) {

            TreeNode* curr = q.front();
            q.pop();
            temp.push_back(curr->val);

            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);

            level_size--;
        }

        if(!forwards) {
            reverse(temp.begin(), temp.end());
        }
        result.push_back(temp);
        forwards = !forwards;

    }

    return result;
}

int main() {

    return 0;
}