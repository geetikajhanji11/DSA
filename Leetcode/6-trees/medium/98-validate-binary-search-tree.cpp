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

bool isValid(TreeNode* root, int range_min, int range_max) {

    if(root == NULL) return true;
    
    if(root->val <= range_min || root->val >= range_max) return false;

    bool is_left_subtree_valid = isValid(root->left, range_min, root->val);
    bool is_right_subtree_valid = isValid(root->right, root->val, range_max);

    return is_left_subtree_valid && is_right_subtree_valid;
}
    
bool inorder(TreeNode* root, TreeNode*& prev) {

    if (root == NULL) return true;
    
    if (!inorder(root->left, prev)) return false;
    if (prev != NULL && prev->val >= root->val) return false;
    prev = root;
    if (!inorder(root->right, prev)) return false;
    
    return true;
}

bool isValidBST(TreeNode* root) {
    // return isValid(root, INT_MIN, INT_MAX);
    TreeNode* prev = NULL;
    return inorder(root, prev);
}

int main() {

    return 0;
}

