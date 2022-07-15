/*******************************************************************
UNION FIND
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int doFind(int node, vector<int> &parent) {
    int super_parent = parent[node];
    while(super_parent != parent[super_parent]) {
        parent[super_parent] = parent[parent[super_parent]];
        super_parent = parent[super_parent];
    }
    return super_parent;
}

int doUnion(int node1, int node2, vector<int> &parent, vector<int> &rank) {

    int node1_super_parent = doFind(node1, parent);
    int node2_super_parent = doFind(node2, parent);

    if(node1_super_parent == node2_super_parent) return 0;

    else if(rank[node1_super_parent] > rank[node2_super_parent]) {
        parent[node2_super_parent] = node1_super_parent;
        rank[node1_super_parent] += rank[node2_super_parent];
    } else {
        parent[node1_super_parent] = node2_super_parent;
        rank[node2_super_parent] += rank[node1_super_parent];
    }

    return 1;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    
    int n = isConnected.size();
    int components = n;

    // 1 based indexing
    vector<int> rank(n+1, 1);
    vector<int> parent(n+1, -1);
    for(int i=1; i<=n; i++) {
        parent[i] = i;
    } 

    for(int i=0; i<n; i++) {
        vector<int> curr_node_is_connected = isConnected[i];
        int curr_node = i + 1;

        // cout<<"\ncurr_node = "<<curr_node;
        for(int j=0; j<curr_node_is_connected.size(); j++) {

            int other_node = j + 1;
            // cout<<"\n\tother_node = "<<other_node;

            if(curr_node_is_connected[other_node-1] == 0) continue; // will not perform union
            if(curr_node == other_node) continue; // same node, skip

            components -= doUnion(curr_node, other_node, parent, rank);
            
        }
    }

    return components;
}

int main() {

    vector<vector<int>> isConnected = {
        {1,0,0,1},
        {0,1,1,0},
        {0,1,1,1},
        {1,0,1,1}
    };

    int ans = findCircleNum(isConnected);
    cout<<"\n\nans = "<<ans;
    return 0;
}