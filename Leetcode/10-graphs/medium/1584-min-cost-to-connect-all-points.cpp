/*******************************************************************
Given array of points, return min cost to connect all points
All points have 1 path b/w them, cost is Manhattan distance

MST problem, Prim's, greedily pick node not in MST & has smallest 
edge cost. Add to MST, & for all its neighbors, try to update min 
dist values, repeat

Time: O(n^2)
Space: O(n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// PRIM'S ALGORITHM
int minCostConnectPoints(vector<vector<int>>& points) {
    
    int n = points.size();

    // index => list of {cost, node}
    unordered_map<int, vector<pair<int,int>>> adj_list; 

    for(int i=0; i<n; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        for(int j=i+1; j<n; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            int distance = abs(x1 - x2) + abs(y1 - y2);
            // undirected graph
            adj_list[i].push_back({distance, j});
            adj_list[j].push_back({distance, i});
        }
    }

    // ----- prim's algorithm ------
    int total_cost = 0;
    unordered_set<int> visited; // maps index of points as visited or not
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > min_heap;

    min_heap.push({0, 0}); // {cost, point_index}

    while(visited.size() < n) {

        pair<int, int> p = min_heap.top();
        min_heap.pop();

        int cost = p.first;
        int i = p.second;

        if(visited.find(i) != visited.end()) continue;

        total_cost += cost;
        visited.insert(i);
        
        auto nbrs = adj_list[i];
        for(auto nbr : nbrs) {
            int nbr_cost = nbr.first;
            int nbr_i = nbr.second;
            min_heap.push({nbr_cost, nbr_i});
        }
    }

    return total_cost;

}

int main() {


    return 0;
}