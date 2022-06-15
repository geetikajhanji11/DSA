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

};

int main() {
    
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);

    g.printAdjList();
    return 0;
}