/*******************************************************************
Tarjan’s Algorithm
*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

class Graph {

    int V;
    list<int> *adjList;

    // undirected graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

public:
    
    // constructor
    Graph(int V, vector<vector<int>>& edges) {
        this->V = V;
        this->adjList = new list<int>[V];
        for(auto edge : edges) {
            addEdge(edge[0], edge[1]);
        }
    }

    // dfs for Tarjan’s Algorithm
    void dfs(int node, int parent, int &time, vector<bool> &visited, vector<int> &discoveryTime, vector<int> &low, vector<vector<int>> &bridges) {

        visited[node] = true;
        discoveryTime[node] = time;
        low[node] = time;
        time++;

        for(int child : adjList[node]) {
            if(child == parent) continue;

            if(!visited[child]) {
                dfs(child, node, time, visited, discoveryTime, low, bridges);
                low[node] = min(low[node], low[child]);
                if(low[child] > discoveryTime[node]) {
                    bridges.push_back({node, child});
                }
            } else {
                low[node] = min(low[node], discoveryTime[child]);
            }
        }
    }

    // Tarjan’s Algorithm
    vector<vector<int>> tarjan() {
        int time = 0;
        vector<bool> visited(V, false);
        vector<int> discoveryTime(V, 0);
        vector<int> low(V, 0);
        vector<vector<int>> bridges;

        for(int node=0; node<V; node++) {
            if(!visited[node]) {
                dfs(node, -1, time, visited, discoveryTime, low, bridges);
            }
        }

        return bridges;
    }

};

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        Graph g(n, connections);
        return g.tarjan();
    }
};