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
    void dfs(int node, int parent, int &time, vector<bool> &visited, vector<int> &discoveryTime, vector<int> &low, vector<bool> &isArticulationPoint) {

        // mark the current node as visited
        visited[node] = true;

        // set the discovery time and low time 
        // as current time
        discoveryTime[node] = time;
        low[node] = time;
        time++;

        // count disconnectedChildren
        int disconnectedChildren = 0;

        // iterate over every child
        for(int child : adjList[node]) {

            // node - parent connection is not counted
            if(child == parent) continue;

            // if child is not already visited,
            // there is a chance it may be a articulation point
            if(!visited[child]) {
                dfs(child, node, time, visited, discoveryTime, low, isArticulationPoint);
                low[node] = min(low[node], low[child]);
                // main condition
                if(low[child] >= discoveryTime[node] && parent != -1) {
                    isArticulationPoint[node] = true;
                }
                disconnectedChildren++;
            } 
            
            // if child is already visited
            else {
                low[node] = min(low[node], discoveryTime[child]);
            }
        }

        // other main condition
        if(parent == -1 && disconnectedChildren > 1) {
            isArticulationPoint[node] = true;
        }
    }

    // Tarjan’s Algorithm
    vector<int> articulationPoints() {
        int time = 0;
        vector<bool> visited(V, false);
        vector<int> discoveryTime(V, 0);
        vector<int> low(V, 0);
        vector<bool> isArticulationPoint(V, false);

        for(int node=0; node<V; node++) {
            if(!visited[node]) {
                dfs(node, -1, time, visited, discoveryTime, low, isArticulationPoint);
            }
        }

        vector<int> result;
        for(int node=0; node<V; node++) {
            if(isArticulationPoint[node]) {
                result.push_back(node);
            }
        }

        return result;
    }

};


int main() {
    
    // int V = 5;
    // vector<vector<int>> edges = {{0,1},{1,2},{2,0},{0,3},{3,4}};

    // int V = 4;
    // vector<vector<int>> edges = {{0,1},{1,2},{2,3}};

    int V = 7;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0},{1,3},{1,4},{1,6},{3,5},{4,5}};
    
    Graph g(V, edges);
    auto res = g.articulationPoints();

    cout<<"Articulation Points:\n";
    for(int point : res) {
        cout<<point<<endl;
    }
	
	return 0;
}