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

bool ancestorExists(TreeNode* root, TreeNode* target, vector<int> &result) {
    if(root == NULL) return false;
    if(root == target) return true;

    bool ancestorIsInLeftSubtree = ancestorExists(root->left, target, result);
    bool ancestorIsInRightSubtree = ancestorExists(root->right, target, result);

    if(ancestorIsInLeftSubtree || ancestorIsInRightSubtree) {
        result.push_back(root->val);
        return true;
    }

    return false;
}

int main() {

    return 0;
}