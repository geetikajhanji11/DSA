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

int closestValue(TreeNode *root, double target) {
    int closest = INT_MAX;
    double closest_diff = INT_MAX;

    TreeNode* curr = root;

    while(curr != NULL) {

        double curr_diff = abs(curr->val - target);
        if(curr_diff < closest_diff) {
            closest_diff = curr_diff;
            closest = curr->val;
        }

        if(target < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }

    }

    return closest;
    
}

int main() {

    return 0;
}