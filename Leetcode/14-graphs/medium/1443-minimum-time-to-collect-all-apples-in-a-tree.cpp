/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // returns true if current node has apple OR
    // any descendent of current node has an apple
    bool nodeHasApple(int node, unordered_map<int, vector<int>> &children, vector<bool> &visited,  vector<bool>& hasApple, int &result) {
    
        // visit the current node
        visited[node] = true;

        // total > 0 means any one child of current node has an apple
        int total = 0; 

        // go over all the children of current node
        for(int child : children[node]) {
            if(visited[child]) continue;

            bool childHasApple = nodeHasApple(child, children, visited, hasApple, result);
            
            // if the child has an apple (means either child actually 
            // has an apple or any decendent of this child has an apple)
            if(childHasApple) {
                // +2 means person went forward and backward from current
                // node to immediate child => 2 paths
                total += 2; 
            }
        }

        // add the paths to final result
        result += total;

        // if any one child has an apple OR 
        // the node itself has an apple, 
        // return TRUE
        return total > 0  || hasApple[node];
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> children;

        // creating undirected graph
        for(auto edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        int result = 0;
        nodeHasApple(0, children, visited, hasApple, result);

        return result;
    }
};