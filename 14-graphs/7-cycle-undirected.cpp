/*******************************************************************
 * DETECT CYCLE IN AN UNDIRECTED GRAPH
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
        adjList = new list<int>[V];
    }

    // add a new edge
    void addEdge(int i, int j, bool undirected = true) {
        adjList[i].push_back(j);
        if(undirected) {
            adjList[j].push_back(i);
        }
    } 

    // recursive part
    bool hasCycleHelper(int curr_vertex, vector<bool> &visited, vector<int> &parent) {
    
        visited[curr_vertex] = true;

        for(int nbr : adjList[curr_vertex]) {

            // go and recursively visit the nbr
            if(!visited[nbr]) {
                parent[nbr] = curr_vertex;
                if(hasCycleHelper(nbr, visited, parent)) {
                    return true;
                }
            }

            // nbr is visited but nbr should not be equal to parent
            else if(nbr != parent[curr_vertex])
                return true;
        } 

        return false;
    }

    // depth first search (LIFO)
    bool hasCycle(int source) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        parent[source] = source;
        return hasCycleHelper(source, visited, parent);
    }

};

bool contains_cycle(int V,vector<pair<int,int> > edges){
    Graph g(V);
    for(auto edge : edges) {
        g.addEdge(edge.first, edge.second);
    }
    return g.hasCycle(0);
}

int main() {
    return 0;
}