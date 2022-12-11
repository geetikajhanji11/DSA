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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    // base case
    if(root == NULL) return root;

    // if we found one of the nodes first,
    // return it
    if(root == p) return p;
    else if(root == q) return q;

    // if there is a split, return the root at which this split occurs
    // if p is left of root and q is right of root
    // or p is right of root and q is left of root
    if(p->val < root->val && root->val < q->val ||
        q->val < root->val && root->val < p->val
    ) {
        return root;
    } 
    
    // if both p, q lie in left, go left until split found
    else if(p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } 
    
    // if both p, q lie in right, go right until split found
    else if(p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}

int main() {

    return 0;
}