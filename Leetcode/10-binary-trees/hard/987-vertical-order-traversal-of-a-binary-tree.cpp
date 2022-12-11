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

void dfs(TreeNode* root, int row, int col, map<int, map<int, vector<int>>> &m) {

    if(root == NULL) return;

    m[col][row].push_back(root->val);

    dfs(root->left, row+1, col-1, m);
    dfs(root->right, row+1, col+1, m);

}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, vector<int>>> m;        
    dfs(root, 0, 0, m);

    vector<vector<int>> result;
    for(auto column : m) {
        vector<int> vertical_col;
        for(auto row : column.second) {
            vector<int> v = row.second;
            sort(v.begin(), v.end());
            vertical_col.insert(vertical_col.end(), v.begin(), v.end());
        }
        result.push_back(vertical_col);
    }

    return result;
}

int main() {

    return 0;
}