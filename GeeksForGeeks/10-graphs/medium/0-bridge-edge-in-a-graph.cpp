/*******************************************************************
Given a Graph of V vertices and E edges and another edge(c - d), 
the task is to find if the given edge is a Bridge. i.e., 
removing the edge disconnects the graph.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ******** ANOTHER WAY (ACCEPTED) ********
void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    for(int nbr : adj[node]) {
        if(!visited[nbr]) {
            dfs(nbr, adj, visited);
        }
    }
}
int isBridge(int V, vector<int> adj[], int c, int d) {
    adj[c].erase(find(adj[c].begin(), adj[c].end(), d));
    adj[d].erase(find(adj[d].begin(), adj[d].end(), c));

    vector<bool> visited(V, false);
    dfs(c, adj, visited);
    
    return !visited[d];    
}

// ******** LOGIC CORRECT (NOT ACCEPTED) ********
void dfs(int node, vector<bool> &visited, vector<int> adj[]) {
    visited[node] = true;
    for(int nbr : adj[node]) {
        if(!visited[nbr]) {
            dfs(nbr, visited, adj);
        }
    }
}

int isBridge(int V, vector<int> adj[], int c, int d) {
    
    // remove d from c's neighbours
    vector<int> c_nbrs;
    for(int nbr : adj[c]) {
        if(nbr != d) {
            c_nbrs.push_back(nbr);
        }
    }

    // remove c from d's neighbours
    vector<int> d_nbrs;
    for(int nbr : adj[d]) {
        if(nbr != c) {
            d_nbrs.push_back(nbr);
        }
    }

    // update adj list
    adj[c] = c_nbrs;
    adj[d] = d_nbrs;

    // dfs on any vertex
    vector<bool> visited(V, false);
    dfs(0, visited, adj);

    for(bool val : visited) {
        if(!visited[V]) return true;
    }

    return false;
}