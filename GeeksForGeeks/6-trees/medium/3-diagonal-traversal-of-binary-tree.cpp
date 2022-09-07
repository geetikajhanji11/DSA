/*******************************************************************
https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
};

// inclusive of root
// keep pushing node and going right  
vector<Node*> getAllRights(Node* root, vector<int> &result) {
    vector<Node*> rights;
    while(root != NULL) {
        rights.push_back(root);
        result.push_back(root->data);
        root = root->right;
    }
    return rights;
}

// diagonal traverse
vector<int> diagonal(Node *root) {

    vector<int> result;

    // first layer is just all the rightmost nodes of tree
    vector<Node*> prevLayer = getAllRights(root, result);

    // for every "prev" node in prevLayer,
    // if prev->left exists, push all right most nodes
    // of prev->left including itself in the next layer vector
    while(!prevLayer.empty()) {
        vector<Node*> currLayer;
        for(Node* prev : prevLayer) {
            if(prev->left != NULL) {
                vector<Node*> temp = getAllRights(prev->left, result);
                currLayer.insert(currLayer.end(), temp.begin(), temp.end());
            }
        }
        prevLayer = currLayer;
    }

    return result;
}