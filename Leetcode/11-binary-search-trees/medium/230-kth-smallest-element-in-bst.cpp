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

void level_order(TreeNode* root, int &k, int &ans) {
    if(root == NULL) return;

    level_order(root->left, k, ans);
    k--;
    if(k == 0) {
        ans = root->val;
        return;
    }
    level_order(root->right, k, ans);
}

// int iterative_level_order(TreeNode* root, int k) {

//     stack<TreeNode*> s;
//     TreeNode* curr_node = root;

//     while(curr_node != NULL && !s.empty()) {

//         while(curr_node != NULL) {
//             s.push(curr_node);
//             curr_node = curr_node->left;
//         }

//         curr_node = s.top(); 
//         k--;
//         if(k == 0) return curr_node->val;
//         s.pop();

//         if(curr_node->right != NULL) {
//             curr_node = curr_node->right;
//         } 

//     }
// }

int kthSmallest(TreeNode* root, int k) {
    // return iterative_level_order(root, k);
    int n = k;
    int ans = -1;
    level_order(root, n, ans);
    return ans;
}

int main() {

    return 0;
}