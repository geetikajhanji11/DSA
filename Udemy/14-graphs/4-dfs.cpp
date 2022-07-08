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
        adjList = new list<int>[V];
    }

    // add a new edge
    void addEdge(int i, int j, bool undirected = true) {
        adjList[i].push_back(j);
        if(undirected) {
            adjList[j].push_back(i);
        }
    } 

    // print the adjacency list
    void printAdjList() {
        for(int i=0; i<V; i++) {
            cout<<"\nVertex "<<i<<" => ";
            for(int j : adjList[i]) {
                cout<<j<<", ";
            }
        }
    }

    // recursive part
    void dfs_helper(int curr_vertex, vector<bool> &visited) {
        cout<<curr_vertex<<", ";
        visited[curr_vertex] = true;

        for(int nbr : adjList[curr_vertex]) {
            if(!visited[nbr]) {
                dfs_helper(nbr, visited);
            }
        } 
    }

    // depth first search (LIFO)
    void dfs(int source) {
        vector<bool> visited(V, false);
        dfs_helper(source, visited);
    }

};

int main() {
    
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    cout<<"DFS\n";
    g.dfs(1);

    return 0;
}