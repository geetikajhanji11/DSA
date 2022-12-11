/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adjList;

    public: 

    // constructor
    Graph(int v) {
        this->V = v;
        this->adjList = new list<int>[V];
    }

    // undirected grpah
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool has_cycle(int node, int prev, vector<int> &visited, int &k) {

        visited[node] = true;
        k++;

        for(auto nbr : adjList[node]) {

            if(visited[nbr] && prev != nbr) return true;

            if(!visited[nbr]) {
                if(has_cycle(nbr, node, visited, k)) return true;
            }
        }

        return false;
    }
    

    bool isValidTree() {
        vector<int> visited(V, false);
        int k = 0;
        
        if(!has_cycle(0, -1, visited, k) && k == V) return true;
        
        return false;
    }
};

bool validTree(int n, vector<vector<int>> &edges) {
    Graph g(n);
    for(auto edge : edges) {
        g.addEdge(edge[0], edge[1]);
    }
    return g.isValidTree();
}

int main() {

    return 0;
}