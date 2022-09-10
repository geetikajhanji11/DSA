/*******************************************************************
Given a binary tree and target node. 
By giving the fire to the target node and fire starts to spread 
in a complete tree. The task is to print the sequence of the burning 
nodes of a binary tree.

Rules for burning the nodes : 
    Fire will spread constantly to the connected nodes only.
    Every node takes the same time to burn.
    A node burns only once.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

// convert tree to undirected graph
void convertTreeToGraph(Node* root, Node* parent, unordered_map<int, vector<int>> &neighbours) {
    if(root == NULL) return;

    if(parent != NULL) neighbours[root->key].push_back(parent->key);
    if(root->left != NULL) neighbours[root->key].push_back(root->left->key);
    if(root->right != NULL) neighbours[root->key].push_back(root->right->key);

    convertTreeToGraph(root->left, root, neighbours);
    convertTreeToGraph(root->right, root, neighbours);
}

// Burn tree function
vector<vector<int>> burnTree(Node* root, int target) {

    // convert tree to a graph
    unordered_map<int, vector<int>> neighbours;
    convertTreeToGraph(root, NULL, neighbours);

    // bfs from target
    queue<int> q;
    unordered_set<int> visited;
    q.push(target);
    visited.insert(target);

    vector<vector<int>> result;
    while(!q.empty()) {

        vector<int> level;
        int size = q.size();

        while(size != 0) {

            int curr = q.front(); q.pop();
            level.push_back(curr);
            
            for(int nbr : neighbours[curr]) {
                if(visited.find(nbr) != visited.end()) continue;
                visited.insert(nbr);
                q.push(nbr);
            }

            size--;
        }

        result.push_back(level);
    }

    return result;

}


// Driver Code
int main() {
    /*      10
           /  \
          12  13
              / \
             14 15
            / \ / \
          21 22 23 24
 
        Let us create Binary Tree as shown
        above */
 
    Node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(13);
 
    root->right->left = newNode(14);
    root->right->right = newNode(15);
 
    root->right->left->left = newNode(21);
    root->right->left->right = newNode(22);
    root->right->right->left = newNode(23);
    root->right->right->right = newNode(24);
    int targetNode = 14;
 
    
    auto res = burnTree(root, targetNode);
    for(auto v : res) {
        for(int num : v) cout<<num<<" ";
        cout<<endl;
    }

    return 0;
}
