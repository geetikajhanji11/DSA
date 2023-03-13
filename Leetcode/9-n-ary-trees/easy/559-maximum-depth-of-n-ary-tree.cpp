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


class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;

        int maxChildDepth = 0;
        for(Node* child : root->children) {
            int currChildDepth = maxDepth(child);
            maxChildDepth = max(maxChildDepth, currChildDepth);
        }

        return maxChildDepth + 1;
    }
};