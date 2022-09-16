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

        // mark the current node as visited
        visited[node] = true;

        // set the discovery time and low time 
        // as current time
        discoveryTime[node] = time;
        low[node] = time;
        time++;

        // iterate over every child
        for(int child : adjList[node]) {

            // node - parent connection is not counted
            if(child == parent) continue;

            // if child is not already visited,
            // there is a chance it may be a bridge
            if(!visited[child]) {
                dfs(child, node, time, visited, discoveryTime, low, bridges);
                low[node] = min(low[node], low[child]);
                // main condition
                if(low[child] > discoveryTime[node]) {
                    bridges.push_back({node, child});
                }
            } 
            
            // if child is already visited, the node - child
            // connection can never be a bridge 
            else {
                low[node] = min(low[node], discoveryTime[child]);
            }
        }
    }

    // Tarjan’s Algorithm
    vector<vector<int>> bridgeEdges() {
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


int main() {
    
    int V = 4;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0},{1,3}};
    
    Graph g(V, edges);
    auto res = g.bridgeEdges();

    cout<<"Bridges:\n";
    for(auto p : res) {
        cout<<p[0]<<"-"<<p[1]<<endl;
    }
	
	return 0;
}