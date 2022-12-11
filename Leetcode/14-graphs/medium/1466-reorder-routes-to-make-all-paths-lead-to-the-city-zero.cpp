/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, vector<int>> &adjList, vector<bool> &is_connected_to_zero, int &ctr, set<pair<int,int>> &connections_set) {

    // current node is always connected to 0
    for(int nbr : adjList[node]) {
        if(is_connected_to_zero[nbr]) continue;
        
        // nbr cannot reach city 0
        // make changes (ctr++) 
        // now it is connected to 0
        if(connections_set.find({nbr, node}) == connections_set.end()) {
            ctr++;
        }

        is_connected_to_zero[nbr] = true;
        dfs(nbr, adjList, is_connected_to_zero, ctr, connections_set);
    }

}

int minReorder(int n, vector<vector<int>>& connections) {

    vector<bool> is_connected_to_zero(n, false);
    set<pair<int,int>> connections_set; // for quick lookup
    unordered_map<int, vector<int>> adjList; // bidirectional

    for(auto connection : connections) {
        int from = connection[0];
        int to = connection[1];
        
        adjList[from].push_back(to);
        adjList[to].push_back(from);

        connections_set.insert({from, to});
    }

    int ctr = 0;

    is_connected_to_zero[0] = true;
    dfs(0, adjList, is_connected_to_zero, ctr, connections_set);
    return ctr;

}

int main() {

    return 0;
}