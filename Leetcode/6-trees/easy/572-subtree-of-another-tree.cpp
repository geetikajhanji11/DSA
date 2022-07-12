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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    else if(p == NULL && q != NULL) return false;
    else if(p != NULL && q == NULL) return false;

    // else
    // Both p and q are NOT NULL
    bool is_curr_same = (p->val == q->val);
    bool is_left_same = isSameTree(p->left, q->left);
    bool is_right_same = isSameTree(p->right, q->right);

    return is_curr_same && is_left_same && is_right_same;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    
    if(root == NULL && subRoot == NULL) return true;
    else if(root == NULL && subRoot != NULL) return false;
    else if(root != NULL && subRoot == NULL) return true;

    // else
    // both root and subRoot are NOT NULL
    bool is_curr_subtree = false;
    if(root->val == subRoot->val) {
        is_curr_subtree = isSameTree(root, subRoot);
    }

    bool does_left_contain_subtree = isSubtree(root->left, subRoot);
    bool does_right_contain_subtree = isSubtree(root->right, subRoot);

    return is_curr_subtree || does_left_contain_subtree || does_right_contain_subtree;
}

int main() {

    return 0;
}