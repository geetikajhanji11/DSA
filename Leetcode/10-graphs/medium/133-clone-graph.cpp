/*******************************************************************
Given ref of a node in connected undirected graph, return deep copy
Both BFS & DFS work, map original node to its copy
Time: O(m + n)
Space: O(n)

//  ---- dfs solution -------
// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if (node == NULL) {
//             return NULL;
//         } 
//         if (m.find(node) == m.end()) {
//             m[node] = new Node(node->val);
//             for (int i = 0; i < node->neighbors.size(); i++) {
//                 Node* neighbor = node->neighbors[i];
//                 m[node]->neighbors.push_back(cloneGraph(neighbor));
//             }
//         }
//         return m[node];
//     }
// private:
//     unordered_map<Node*, Node*> m;
// };
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


Node* cloneGraph(Node* node) {
        
    if(node == NULL) return NULL;

    unordered_map<int, Node*> m;
    unordered_map<Node*, bool> visited;

    queue<Node*> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {

        Node* curr_node = q.front();
        q.pop();

        // making clone
        Node* curr_node_clone = NULL;
        if(m.find(curr_node->val) != m.end()) {
            curr_node_clone = m[curr_node->val];
        } else {
            curr_node_clone = new Node(curr_node->val);
            m.insert({curr_node->val, curr_node_clone});
        }
        
        vector<Node*> neighbours_clone;
        for(Node* nbr : curr_node->neighbors) {
            Node* nbr_clone = NULL;
            if(!visited[nbr]) {
                nbr_clone = new Node(nbr->val);
                m.insert({nbr->val, nbr_clone});
                q.push(nbr);
                visited[nbr] = true;
            } else {
                nbr_clone = m[nbr->val];
            }

            neighbours_clone.push_back(nbr_clone);

        }
        curr_node_clone->neighbors = neighbours_clone;
    }

    return m[node->val];
}

int main() {

    return 0;
}