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

// int result = 0;
// pair<int, int> getDiameterAndHeight(TreeNode* root) {
//     if(root == NULL) return {0, -1};

//     auto left = getDiameterAndHeight(root->left);
//     auto right = getDiameterAndHeight(root->right);
//     int diameter = left.second + right.second + 1 + 1;
//     int height = 1 + max(left.second, right.second);

//     result = max(result, diameter);

//     return {diameter, height};
// }

// int diameterOfBinaryTree(TreeNode* root) {
    
//     getDiameterAndHeight(root);
//     return result;
   
// }

pair<int, int> getDiameterAndHeight(TreeNode* root) {
    if(root == NULL) return {0, -1};

    auto left = getDiameterAndHeight(root->left);
    auto right = getDiameterAndHeight(root->right);

    int diameter = left.second + right.second + 2;
    int max_diameter = max(diameter, max(left.first, right.first));

    int height = 1 + max(left.second, right.second);

    return {max_diameter, height};
}

int diameterOfBinaryTree(TreeNode* root) {
    auto result = getDiameterAndHeight(root);
    return result.first;
}


int main() {

    return 0;
}