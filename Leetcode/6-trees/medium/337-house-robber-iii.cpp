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

// pair => {rob current node, did not rob current node}
pair<int, int> robHouse(TreeNode* root) {
    if(root == NULL) return {0, 0};

    auto robLeft = robHouse(root->left);
    auto robRight = robHouse(root->right);

    int robCurrent = root->val + robLeft.second + robRight.second;
    int didNotRobCurrent = max(robLeft.first, robLeft.second) + max(robRight.first, robRight.second);

    return {robCurrent, didNotRobCurrent};
}

int rob(TreeNode* root) {
    auto result = robHouse(root);
    return max(result.first, result.second);
}

int main() {

    return 0;
}