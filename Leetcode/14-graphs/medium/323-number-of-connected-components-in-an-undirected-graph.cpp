/*******************************************************************
Time complexity of above solution is O(V + E) as it does simple 
DFS for given graph. 

// ------ UNION FIND ------
Graph of n nodes, given edges array, return # of connected components
    Ex. n = 5, edges = [[0,1],[1,2],[3,4]] -> 2

    Union find, for each edge combine, if already in same set keep traversing
    If not in same set, decrement count by 1, count will store # of components

    Time: O(n)
    Space: O(n)

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents;
        vector<int> ranks;
        for (int i = 0; i < n; i++) {
            parents.push_back(i);
            ranks.push_back(1);
        }
        
        int result = n;
        for (int i = 0; i < edges.size(); i++) {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            result -= doUnion(parents, ranks, n1, n2);
        }
        return result;
    }
private:
    int doFind(vector<int>& parents, int n) {
        int p = parents[n];
        while (p != parents[p]) {
            parents[p] = parents[parents[p]];
            p = parents[p];
        }
        return p;
    }
    
    int doUnion(vector<int>& parents, vector<int>& ranks, int n1, int n2) {
        int p1 = doFind(parents, n1);
        int p2 = doFind(parents, n2);
        if (p1 == p2) {
            return 0;
        }
        
        if (ranks[p1] > ranks[p2]) {
            parents[p2] = p1;
            ranks[p1] += ranks[p2];
        } else {
            parents[p1] = p2;
            ranks[p2] += ranks[p1];
        }
        
        return 1;
    }
};
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

    void dfs(int node, vector<bool> &visited) {
        if(visited[node]) return;
        cout<<node<<", ";
        visited[node] = true;

        auto nbrs = adjList[node];
        for(int nbr : nbrs) {
            dfs(nbr, visited);
        }
    }

    int components() {
        int ctr = 0;
        vector<bool> visited(V, false);

        for(int node=0; node<V; node++) {
            if(!visited[node]) {
                cout<<"\nConnected graph = ";
                dfs(node, visited);
                ctr++;
            }
        }

        return ctr;
    }
};

int countComponents(int n, vector<vector<int>>& edges) {
    Graph g(n);
    for(auto edge : edges) {
        g.addEdge(edge[0], edge[1]);
    }
    return g.components();
}

int main() {

    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {3,4}
    };

    int components = countComponents(5, edges);
    cout<<"\nComponents = "<<components;
    return 0;
}