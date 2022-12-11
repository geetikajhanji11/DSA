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

/*  *********  SAME CODE, BUT SHORTER *************

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j) {
        if (i > j) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[index]);
        
        int split = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[index] == inorder[i]) {
                split = i;
                break;
            }
        }
        index++;
        
        root->left = build(preorder, inorder, index, i, split - 1);
        root->right = build(preorder, inorder, index, split + 1, j);
        
        return root;
    }
};

*/

TreeNode* build(vector<int> preorder, vector<int> inorder) {

    if(preorder.size() == 0) return NULL;

    int root_val = preorder[0];
    TreeNode* root = new TreeNode(root_val);

    // calculating new inorders
    vector<int> left_inorder;
    vector<int> right_inorder;

    int root_index = -1;
    for(int i=0; i<inorder.size(); i++) {
        int num = inorder[i];
        if(num == root_val) {
            root_index = i;
            continue;
        }
        if(root_index == -1) {
            left_inorder.push_back(num);
        } else {
            right_inorder.push_back(num);
        }
    }

    // calculating new preorders
    int left_length = left_inorder.size();
    int right_length = right_inorder.size();

    vector<int> left_preorder;
    vector<int> right_preorder;

    int i = 1;
    while(left_length != 0) {
        left_preorder.push_back(preorder[i]);
        i++;
        left_length--;
    }
    while(right_length != 0) {
        right_preorder.push_back(preorder[i]);
        i++;
        right_length--;
    }

    // creating the left and right subtrees
    TreeNode* left_node = build(left_preorder, left_inorder);
    TreeNode* right_node = build(right_preorder, right_inorder);

    // merging them
    root->left = left_node;
    root->right = right_node;

    return root;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, inorder);
}

int main() {

    return 0;
}