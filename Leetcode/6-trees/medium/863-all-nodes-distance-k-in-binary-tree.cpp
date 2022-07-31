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

void get_nodes_at_level_k(TreeNode* root, int k, vector<int> &nodes) {
    if(root == NULL) return;
    if(k == 0) {
        nodes.push_back(root->val);
        return;
    }
    get_nodes_at_level_k(root->left, k-1, nodes);
    get_nodes_at_level_k(root->right, k-1, nodes);

}

int distance_from_target(TreeNode* root, TreeNode* target, int k, vector<int> &nodes) {

    if(root == NULL) return -1;

    if(root == target) {
        get_nodes_at_level_k(root, k, nodes);
        return 0;
    }

    // distance of target node from left child
    int DL = distance_from_target(root->left, target, k, nodes);
    if(DL != -1) {
        // current node is at kth position itself
        if(DL + 1 == k) {
            nodes.push_back(root->val);
        } 
        // kth node lies in right subtree at k-DL-2 distance
        else {
            get_nodes_at_level_k(root->right, k-DL-2, nodes);
        }
        return DL + 1;
    }

    // distance of target node from right child
    int DR = distance_from_target(root->right, target, k, nodes);
    if(DR != -1) {
        // current node is at kth position itself
        if(DR + 1 == k) {
            nodes.push_back(root->val);
        } 
        // kth node lies in left subtree at k-DL-2 distance
        else {
            get_nodes_at_level_k(root->left, k-DR-2, nodes);
        }
        return DR + 1;
    }

    // did not find target
    return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> nodes;        
    distance_from_target(root, target, k, nodes);
    return nodes;
}

int main() {

    return 0;
}