/*******************************************************************
We traverse childs first (post-order traversal), and return the 
ballance of coins. 

For example, if we get '+3' from the left child, 
that means that the left subtree has 3 extra coins to move out. 

If we get '-1' from the right child, we need to move 1 coin in. 
So, we increase the number of moves by 4 (3 moves out left + 1 moves in right). 

We then return the final ballance: 
    r->val (coins in the root) + 3 (left) + (-1) (right) - 1 (keep one coin for the root).
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

    int coinsRequired(TreeNode* root, int &moves) {
        if(root == NULL) return 0;

        int left = coinsRequired(root->left, moves);
        int right = coinsRequired(root->right, moves);

        moves += abs(left) + abs(right);

        return left + right + root->val - 1;
    }

public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        coinsRequired(root, moves);
        return moves;
    }
};