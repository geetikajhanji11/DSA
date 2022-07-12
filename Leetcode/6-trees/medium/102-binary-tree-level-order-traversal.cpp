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

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);
    q.push(NULL);

    vector<vector<int>> result;
    vector<int> level;
        
    while(true) {

        if(q.front() == NULL) {
            q.pop();
            q.push(NULL);
            result.push_back(level);
            level.clear();
        }

        if(q.front() == NULL) break;
    
        TreeNode* curr_node = q.front();
        if(curr_node->left != NULL) q.push(curr_node->left);
        if(curr_node->right != NULL) q.push(curr_node->right);
        level.push_back(curr_node->val);
        q.pop();
    
    }

    if(root == NULL) {
        result.clear();
        return result;
    }

    return result;
}

int main() {

    return 0;
}