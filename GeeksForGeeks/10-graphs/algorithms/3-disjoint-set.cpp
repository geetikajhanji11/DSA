/*******************************************************************
Can be used in almost all questions
as it supports 0 and 1 based indexing both
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:

    DisjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {
        if(node == parent[node]) return node;

        int ultimateParent = findUltimateParent(parent[node]);
        parent[node] = ultimateParent; // path compression

        return ultimateParent;
    }

    void unionByRank(int u, int v) {
        int parent_u = findUltimateParent(u);
        int parent_v = findUltimateParent(v);

        if(parent_u == parent_v) return;

        if(rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        } else if(rank[parent_v] > rank[parent_u]) {
            parent[parent_u] = parent_v;
        } else {
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
    }

    void unionBySize(int u, int v) {
        int parent_u = findUltimateParent(u);
        int parent_v = findUltimateParent(v);

        if(parent_u == parent_v) return;

        if(size[parent_u] > size[parent_v]) {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        } else {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
    }

};

int main() {

    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout<<"\nSame";
    else cout<<"\nNot Same";

    ds.unionByRank(3, 7);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout<<"\nSame";
    else cout<<"\nNot Same";
    
    return 0;
}