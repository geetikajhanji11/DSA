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

    // ITERATIVE PATH ALGO (Printed in reverse order)
    void printPathIterative(int source, int destination, vector<int> &parent) {
        while(destination != source) {
            cout<<destination<<", ";
            destination = parent[destination];
        }
        cout<<source;
    }
        

    // RECURSIVE ALGO
    // source -> destination
    void printPathRecur(int source, int destination, int curr_vertex, vector<int> &parent) {
        if(source == curr_vertex) {
            cout<<source<<" --> ";
            return;
        }
        printPathRecur(source, destination, parent[curr_vertex], parent);
        
        if(curr_vertex == destination) cout<<curr_vertex;
        else cout<<curr_vertex<<" --> ";
    }

    // breadth first search (FIFO)
    void shortestBFS(int source) {
        vector<bool> visited(V, false);
        queue<int> Q;
        vector<int> distance(V, 0);
        vector<int> parent(V, -1);

        Q.push(source);
        visited[source] = true;
        parent[source] = source;
        distance[source] = 0;

        while(!Q.empty()) {

            int curr_vertex = Q.front();
            cout<<curr_vertex<<", ";
            
            list<int> nbrs = adjList[curr_vertex];
            for(int nbr : nbrs) {
                if(!visited[nbr]) {
                    Q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = curr_vertex;
                    distance[nbr] = distance[parent[nbr]] + 1;
                }
            }
            Q.pop();
        }

        // print the shortest distance
        cout<<"\n\nSOURCE = "<<source;
        for(int i=0; i<V; i++) {
            cout<<"\nShortest distance to "<<i<<" = "<<distance[i];
        }

        // print the path from a source to any destination
        // recursive
        cout<<"\n\nPATH (Recursive)";
        for(int i=0; i<V; i++) {
            cout<<"\nPath for "<<i<<": ";
            int destination = i;
            int curr_node = destination;
            printPathRecur(source, destination, curr_node, parent);
        }

        // iterative
        cout<<"\n\nPATH (Iterative)";
        for(int i=0; i<V; i++) {
            cout<<"\nPath for "<<i<<": ";
            int destination = i;
            printPathIterative(source, destination, parent);
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

    cout<<"SHORTEST DISTANCE BFS\n";
    // g.bfs(1);
    g.shortestBFS(1);

    return 0;
}