/*******************************************************************
Signal sent from node k to network of n nodes, return time for all 
nodes to receive it
Ex. times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2 -> 2
                u,v,w -> 
                    u = source node, 
                    v = target node, 
                    w = signal travel time

Shortest path from node k to every other node, Dijkstra's to find 
fastest path

Time: O(V + E log V)
Space: O(V + E)

// Same Code but he uses priority queue instead of set
// but it is technically the same thing
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0];
            int dest = times[i][1];
            int time = times[i][2];
            adj[source].push_back({time, dest});
        }
        
        vector<int> signalReceiveTime(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        
        // time for start node is 0
        signalReceiveTime[k] = 0;
        
        while (!pq.empty()) {
            int currNodeTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            if (currNodeTime > signalReceiveTime[currNode]) {
                continue;
            }
            
            // send signal to adjacent nodes
            for (int i = 0; i < adj[currNode].size(); i++) {
                pair<int, int> edge = adj[currNode][i];
                int time = edge.first;
                int neighborNode = edge.second;
                
                // fastest signal time for neighborNode so far
                if (signalReceiveTime[neighborNode] > currNodeTime + time) {
                    signalReceiveTime[neighborNode] = currNodeTime + time;
                    pq.push({signalReceiveTime[neighborNode], neighborNode});
                }
            }
        }
        
        int result = INT_MIN;
        for (int i = 1; i <= n; i++) {
            result = max(result, signalReceiveTime[i]);
        }
        
        if (result == INT_MAX) {
            return -1;
        }
        return result;
    }
};
*******************************************************************/

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

    // undirected grpah
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({weight, v});
    }

    // dijkshtra's algorithm
    int dijkstra(int source) {
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

        int maximum_time = -1;
            
        for(int i=1; i<V; i++) {
            maximum_time = max(maximum_time, distance[i]);
        }

        return maximum_time == INT_MAX ? -1 : maximum_time;

    }
};

int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    Graph g(n+1);
    for(auto time : times) {
        g.addEdge(time[0], time[1], time[2]);
    }

    return g.dijkstra(k);

}

int main() {
    

    return 0;
}