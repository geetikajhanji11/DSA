/*******************************************************************
Given undirected graph, return an edge that can be removed to make a tree
Ex. edges = [[1,2],[1,3],[2,3]] -> [2,3]

If n nodes & n edges, guaranteed a cycle
How to know creating cycle? When connecting a node already connected
Union Find: can find this redundant edge, track parents & ranks

Time: O(n)
Space: O(n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int doFind(int node, vector<int> &parent) {
    int root_parent = parent[node];
    while(root_parent != parent[root_parent]) {
        parent[root_parent] = parent[parent[root_parent]]; // path compression
        root_parent = parent[root_parent];
    }
    return root_parent;
}

bool doUnion(int node1, int node2, vector<int> &parent, vector<int> &rank) {
    int p1 = doFind(node1, parent);
    int p2 = doFind(node2, parent);

    if(p1 == p2) return false;

    if(rank[p1] > rank[p2]) {
        parent[p2] = p1;
        rank[p1] += rank[p2];
    } else {
        parent[p1] = p2;
        rank[p2] += rank[p1];
    }

    return true;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    int n = edges.size();
    vector<int> parent(n+1, 0);
    for(int i=0; i<=n; i++) parent[i] = i;

    vector<int> rank(n+1, 1);

    vector<int> result;
    for(auto edge : edges) {
        int node1 = edge[0];
        int node2 = edge[1];
        if(!doUnion(node1, node2, parent, rank)) {
            result.push_back(node1);
            result.push_back(node2);
            return result;      
        }
    }
    return result;
}

int main() {

    return 0;
}