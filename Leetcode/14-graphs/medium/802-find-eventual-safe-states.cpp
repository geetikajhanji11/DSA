/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool isSafe(int node, vector<bool> &visited, vector<vector<int>>& graph, unordered_map<int, bool> &safe) {

        // reached a terminal node
        if(graph[node].empty()) return true;

        // check if state was already computed
        if(safe.find(node) != safe.end()) return safe[node];

        // reached a node that has been visited in the current path
        // but it was not safe since none of its path leads to
        // a terminal node
        if(visited[node]) {
            return safe[node] = false;
        }

        // visit the current node
        visited[node] = true;

        // run dfs on every nbr of the current node
        for(int nbr : graph[node]) {
            if(!isSafe(nbr, visited, graph, safe)) {
                return safe[node] = false;
            }
        }

        // current node is safe
        return safe[node] = true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector<bool> visited(n, false);
        unordered_map<int, bool> safe; // true => safe | false => unsafe

        vector<int> result;
        for(int i=0; i<n; i++) {
            if(isSafe(i, visited, graph, safe)) {
                result.push_back(i);
            }
        }

        return result;

    }
};