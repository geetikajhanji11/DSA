/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // edge case
        if(n <= 2) {
            vector<int> result;
            for(int i=0; i<n; i++) {
                result.push_back(i);
            }
            return result;
        }

        // construct the adjacency list for graph
        unordered_map<int, unordered_set<int>> neighbours;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            neighbours[u].insert(v);
            neighbours[v].insert(u);
        }

        // initialize the first layer of leaves
        vector<int> leaves;
        for(int i=0; i<n; i++) {
            if(neighbours[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        // trim the leaves until reaching the centroids
        int remainingNodes = n;
        while(remainingNodes > 2) {

            remainingNodes -= leaves.size();
            vector<int> newLeaves;

            // remove all the leaves
            while(!leaves.empty()) {

                // removing the current leaf
                int leaf = leaves[leaves.size() - 1];
                leaves.pop_back();

                // get that one neighbour of leaf
                int neighbourOfLeaf = *neighbours[leaf].begin();

                // remove the edge (neighbourOfLeaf) <=> (leaf)
                neighbours[neighbourOfLeaf].erase(leaf);
                neighbours[leaf].erase(neighbourOfLeaf);

                // check if the neighbour became a leaf node
                if(neighbours[neighbourOfLeaf].size() == 1) {
                    newLeaves.push_back(neighbourOfLeaf);
                }
            }

            // reset leaves for next iteration
            leaves = newLeaves;
        }  

        // the final leaves are the centroid of the graph
        return leaves;

    }
};