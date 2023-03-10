/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ancestors(n);
        
        vector<vector<int>> graph(n);
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }


        for(int node=0; node<n; node++) {
            
            queue<int> q;
            q.push(node);
            vector<bool> visited(n, false);

            while(!q.empty()) {
                int curr = q.front(); q.pop();
                for(int child : graph[curr]) {
                    if(visited[child]) continue;
                    ancestors[child].push_back(node);
                    q.push(child);
                    visited[child] = true;
                }
            }

        }
        
        return ancestors;

    }
};