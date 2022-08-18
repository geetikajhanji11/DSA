/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void dfs(Node* root, vector<int> &result) {
    if(root == NULL) return;
    result.push_back(root->val);
    for(Node* child : root->children) {
        dfs(child, result);
    }
}


vector<int> preorder(Node* root) {
    vector<int> result;
    dfs(root, result);
    return result;
}


int main() {

    return 0;
}