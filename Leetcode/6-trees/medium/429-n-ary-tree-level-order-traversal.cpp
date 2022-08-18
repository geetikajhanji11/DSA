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

vector<vector<int>> levelOrder(Node* root) {
    
    if(root == NULL) return {};

    queue<Node*> q;
    q.push(root);

    vector<vector<int>> result;

    while(!q.empty()) {
        int size = q.size();
        vector<int> level;

        while(size != 0) {
            Node* curr = q.front();
            q.pop();
            level.push_back(curr->val);
            for(Node* child : curr->children) {
                q.push(child);
            }
            size--;
        }

        result.push_back(level);
    }

    return result;
}

int main() {

    return 0;
}