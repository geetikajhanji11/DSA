#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>> *adjList;

    public:
    
    // constructor
    Graph(int v) {
        this->V = v;
        this->adjList = new list<pair<int, int>>[V];
    }

    // add a new edge with weights
    void addEdge(int i, int j, int weight, bool undirected=true) {
        adjList[i].push_back({j, weight});
        if(undirected) {
            adjList[j].push_back({i, weight});
        }
    }

    // display graph with weights
    void printAdjList() {
        for(int i=0; i<V; i++) {
            cout<<"\nVertex "<<i<<" --> ";
            for(auto p : adjList[i]) {
                cout<<"("<<p.first<<", "<<p.second<<" wt), ";
            }
        }
    }
};

int main() {

    Graph g(6);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 4, 2);
    g.addEdge(2, 1, 3);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 5, 5);
    g.addEdge(2, 3, 6);
    g.addEdge(3, 5, 7);

    g.printAdjList();
    return 0;
}