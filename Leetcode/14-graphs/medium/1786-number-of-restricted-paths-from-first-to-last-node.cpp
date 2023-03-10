/*******************************************************************
TLE
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int MOD = pow(10, 9) + 7;
 
    vector<int> dijkshtra(int source, vector<vector<vector<int>>> &graph) {
        
        vector<int> distance(source + 1, INT_MAX);
        distance[source] = 0;

        set<pair<int, int>> s; // node, distanceTillNode 
        s.insert({source, 0});
         

        while(!s.empty()) {

            auto p = s.begin();
            
            int node = p->first;
            int distanceTillNode = p->second;

            s.erase(p);

            for(auto v : graph[node]) {
                int nbr = v[0];
                int edgeWeight = v[1];

                if(distanceTillNode + edgeWeight < distance[nbr]) {
                    auto already_present_pair = s.find({nbr, distance[nbr]});
                    if(already_present_pair != s.end()) {
                        s.erase(already_present_pair);
                    }

                    distance[nbr] = distanceTillNode + edgeWeight;
                    s.insert({nbr, distance[nbr]});
                }

            }
        }

        return distance;

    }


    int totalPaths(int node, vector<int> &dp, int &lastNode, vector<vector<vector<int>>> &graph, vector<int> &distanceToLastNode) {
        if(node == lastNode) return 1;

        if(dp[node] != INT_MIN) return dp[node];

        int paths = 0;
        for(auto v : graph[node]) {
            int nbr = v[0];
            if(distanceToLastNode[node] > distanceToLastNode[nbr]) {
                paths += totalPaths(nbr, dp, lastNode, graph, distanceToLastNode);
                paths = paths % MOD;
            } 
        }

        dp[node] = paths;
        return dp[node];
    }
    

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {

        vector<vector<vector<int>>> graph(n + 1);

        for(auto edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> distanceToLastNode = dijkshtra(n, graph);

        int paths = 0;
        vector<int> dp(n+1, INT_MIN);

        return totalPaths(1, dp, n, graph, distanceToLastNode);
    }
};