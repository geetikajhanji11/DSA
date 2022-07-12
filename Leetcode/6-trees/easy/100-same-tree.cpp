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

    bool is_curr_same = p->val == q->val;
    bool is_left_same = isSameTree(p->left, q->left);
    bool is_right_same = isSameTree(p->right, q->right);

    return is_curr_same && is_left_same && is_right_same;
}

int main() {

    return 0;
}