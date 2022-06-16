/*******************************************************************
 * DIJKSHTRA ALGORITHM
 * 
 * For Weighted Graphs
 * Single Source Shortest Path
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// sort the SET in increasing order of weights
// a.first = weight
// a.second = node
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first <= b.first;
}

class Graph {
    int V;
    list<pair<int, int>> *adjList;

    public: 

    // constructor
    Graph(int v) {
        this->V = v;
        this->adjList = new list<pair<int, int>>[V];
    }

    // undirected grpah
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({weight, v});
        adjList[v].push_back({weight, u});
    }

    // dijkshtra's algorithm
    int dijkstra(int source, int destination) {
        vector<int> distance(V, INT_MAX);
        distance[source] = 0;

        // set is sorted in the increasing order of the weights 
        // of the nodes
        set<pair<int, int>> s;

        // the source has a distance of 0
        s.insert({0, source});

        // logic
        while(!s.empty()) {
            auto it = s.begin();

            int node = it->second;
            int distanceTillNode = it->first;

            s.erase(it);

            // iterate over nbrs of node
            for(auto nbr_pair : adjList[node]) {
                int nbr = nbr_pair.second;
                int edge_weight = nbr_pair.first;
                if(distanceTillNode + edge_weight < distance[nbr]) {

                    // remove if nbr already exists
                    auto already_present_pair = s.find({distance[nbr], nbr});
                    if(already_present_pair != s.end()) {
                        s.erase(already_present_pair);
                    }
                    
                    // insert the updated new pair for current nbr
                    distance[nbr] = distanceTillNode + edge_weight;
                    s.insert({distance[nbr], nbr});
                }
            }
            
        }

        for(int i=0; i<V; i++) {
            cout<<"Node i = "<<i<<", Distance = "<<distance[i]<<endl;
        }

        return distance[destination];

    }
};

int main() {

    Graph g(5);
    g.addEdge(0,1,1);
        g.addEdge(1,2,1);
        g.addEdge(0,2,4);
        g.addEdge(0,3,7);
        g.addEdge(3,2,2);
        g.addEdge(3,4,3);

    g.dijkstra(0, 4);

    return 0;
} 