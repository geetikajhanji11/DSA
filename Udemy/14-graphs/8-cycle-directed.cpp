/*******************************************************************
 * DETECT CYCLE IN AN DIRECTED GRAPH
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

    // directed graph
    void addEdge(int i, int j) {
        adjList[i].push_back(j);
    } 

    // recursive part
    bool hasCycleHelper(int curr_vertex, vector<bool> &visited, vector<bool> &curr_path_stack) {
    
        // arrive at node
        visited[curr_vertex] = true;
        curr_path_stack[curr_vertex] = true;

        // logic
        for(int nbr : adjList[curr_vertex]) {
            if(curr_path_stack[nbr]) {
                return true;
            }
            else if(!visited[nbr]) {
                if(hasCycleHelper(nbr, visited, curr_path_stack)) {
                    return true;
                } 
            }
        }

        // stack popping out
        curr_path_stack[curr_vertex] = false;
        return false;

    }

    // depth first search (LIFO)
    bool hasCycle() {
        vector<bool> visited(V, false);
        vector<bool> curr_path_stack(V, false);
        return hasCycleHelper(0, visited, curr_path_stack);
    }

};

bool contains_cycle(int V, vector<pair<int,int> > edges){
    Graph g(V);
    for(auto edge : edges) {
        g.addEdge(edge.first, edge.second);
    }
    return g.hasCycle();
}

int main() {
    return 0;
}