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

    // breadth first search (FIFO)
    void bfs(int source) {
        vector<bool> visited(V, false);
        queue<int> Q;

        Q.push(source);
        visited[source] = true;

        while(!Q.empty()) {

            int curr_vertex = Q.front();
            cout<<curr_vertex<<", ";
            
            list<int> nbrs = adjList[curr_vertex];
            for(int nbr : nbrs) {
                if(!visited[nbr]) {
                    Q.push(nbr);
                    visited[nbr] = true;
                }
            }
            Q.pop();
        }
    }

    
    // breadth first search (FIFO)
    // FOR DISCONNECTED GRAPH
    void bfs_disconnected(int n) {

        vector<bool> visited(V, false);
        queue<int> Q;

        int source = 0;
        
        for(int i=0; i<n; i++) {
            source = i;
            
            if(visited[source]) continue;
            cout<<"\nSOURCE = "<<source<<" => ";

            Q.push(source);
            visited[source] = true;

            while(!Q.empty()) {

                int curr_vertex = Q.front();
                cout<<curr_vertex<<", ";
                
                list<int> nbrs = adjList[curr_vertex];
                for(int nbr : nbrs) {
                    if(!visited[nbr]) {
                        Q.push(nbr);
                        visited[nbr] = true;
                    }
                }
                Q.pop();
            }

        }
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

    cout<<"BFS\n";
    g.bfs(1);

    return 0;
}