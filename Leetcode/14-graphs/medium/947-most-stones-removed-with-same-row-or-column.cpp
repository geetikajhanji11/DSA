/*******************************************************************
https://www.youtube.com/watch?v=OwMNX8SPavM&ab_channel=takeUforward
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ****************** UNION - FIND SOLUTION ******************
class DisjointSet {
public:

    vector<int> parent;
    vector<int> size;

    DisjointSet(int n) {
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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0;
        int maxCol = 0;

        for(auto stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        int ds_n = maxRow + maxCol + 1;
        DisjointSet ds(ds_n);
        unordered_set<int> seenNodes;

        for(auto stone : stones) {
            int u = stone[0];
            int v = stone[1] + maxRow + 1;
            ds.unionBySize(u, v);
            seenNodes.insert(u);
            seenNodes.insert(v);
        }

        int validConnectedComponents = 0;
        for(int node : seenNodes) {
            if(ds.findUltimateParent(node) == node) {
                validConnectedComponents++;
            }
        }

        return n - validConnectedComponents;
    }
};

// ****************** DFS SOLUTION ****************** 
class Solution {
    int dfs(int stone, unordered_map<int, vector<int>> &rows, unordered_map<int, vector<int>> &cols, vector<bool> &visited, vector<vector<int>> &stones) {
        if(visited[stone]) return 0;

        visited[stone] = true;

        int stoneRow = stones[stone][0];
        int stoneCol = stones[stone][1];

        for(int currStone : rows[stoneRow]) {
            dfs(currStone, rows, cols, visited, stones);
        }

        for(int currStone : cols[stoneCol]) {
            dfs(currStone, rows, cols, visited, stones);
        }

        return 1;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        unordered_map<int, vector<int>> rows;
        unordered_map<int, vector<int>> cols;

        for(int stone=0; stone<n; stone++) {
            int stoneRow = stones[stone][0];
            int stoneCol = stones[stone][1];

            rows[stoneRow].push_back(stone);
            cols[stoneCol].push_back(stone);
        }

        vector<bool> visited(n, false);

        int components = 0;
        for(int stone=0; stone<n; stone++) {
            components += dfs(stone, rows, cols, visited, stones);
        }

        return n - components;
    }
};