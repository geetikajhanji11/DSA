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

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL && root2 != NULL) return false;
        if(root1 != NULL && root2 == NULL) return false;

        if(root1->val != root2->val) return false;

        bool checkLeft1 = flipEquiv(root1->left, root2->left);
        bool checkRight1 = flipEquiv(root1->right, root2->right);
        bool op1 = checkLeft1 && checkRight1;

        bool checkLeft2 = flipEquiv(root1->left, root2->right);
        bool checkRight2 = flipEquiv(root1->right, root2->left);
        bool op2 = checkLeft2 && checkRight2;

        return op1 || op2;

    }
};