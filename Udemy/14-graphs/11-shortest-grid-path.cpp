/*******************************************************************
 * SHORTEST GRID PATH
 * 
 * Given a 2D grid, each cell of which contains integer cost which
 * represents a cost to traverse through that cell, we need to find
 * a path from top left to bottom right cell by which total cost
 * incurred is minimum.
 * It is assumed that negative cost cycles do not exist in input
 * matrix

 * SAMPLE INPUT
 * grid = {
        {31, 100, 65, 12, 18},
        {10, 13, 47, 157, 6},
        {100, 113, 174, 11, 33},
        {88, 124, 41, 20, 140},
        {99, 32, 111, 41, 20}
    };

 * OUTPUT
 * 327 [= 31 + 10 + 13 + 47 + 65 + 12 + 18 + 6 + 33 + 11 + 20 + 41 + 20]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/**************** DFS & BACKTRACKING SOLUTION ****************/
bool cellInBounds(int i, int j, vector<vector<int>> &grid) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
}

void dfs(vector<vector<int> > grid, int i, int j, vector<vector<int>> &visited, int total_cost, int &min_cost) {

    // cell is not in bounds
    if(!cellInBounds(i, j, grid)) return;

    // cell already visited, do not traverse
    if(visited[i][j]) return;

    // get the current cost
    int current_cost = grid[i][j];

    // reached the destination
    if(i == grid.size() - 1 && j == grid[0].size() - 1) {
        if(total_cost + current_cost < min_cost) {
            min_cost = total_cost + current_cost;
        }
    }

    // mark the current node as visited
    visited[i][j] = true;

    // 4 directions => up, down, left, right
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    // recursive call in each direction
    int cost = INT_MAX;
    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        dfs(grid, next_i, next_j, visited, total_cost + current_cost, min_cost);
    }

    // backtracking
    visited[i][j] = false;
}

int shortest_path(vector<vector<int> > grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));

    int min_cost = INT_MAX;
    dfs(grid, 0, 0, visited, 0, min_cost);

    return min_cost;
}

/**************** DIJKSHTRA SOLUTION ****************/

int shortest_path_djk(vector<vector<int> > grid) {

    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
    distance[0][0] = grid[0][0];

    // 0: distance till node
    // 1 : i
    // 2 : j
    set<vector<int>> s;

    s.insert({grid[0][0], 0, 0});
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    while(!s.empty()) {
        auto itr = s.begin();

        int distance_till_node = (*itr)[0];
        int i = (*itr)[1];
        int j = (*itr)[2];

        s.erase(itr);

        for(int k=0; k<4; k++) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            if(!cellInBounds(next_i, next_j, grid)) continue;

            int nbr = grid[next_i][next_j];
            int new_distance = distance_till_node + nbr;

            if(new_distance < distance[next_i][next_j]) {

                auto nbr_itr = s.find({distance[next_i][next_j], next_i, next_j});
                if(nbr_itr != s.end()) {
                    s.erase(nbr_itr);
                }
                distance[next_i][next_j] = new_distance;
                s.insert({new_distance, next_i, next_j});
            }
        }

    }


    return distance[rows-1][cols-1];
}

int main() {

    vector<vector<int>> grid = {
        {31, 100, 65, 12, 18},
        {10, 13, 47, 157, 6},
        {100, 113, 174, 11, 33},
        {88, 124, 41, 20, 140},
        {99, 32, 111, 41, 20}
    };

    cout<<"\nDFS & BACKTRAKKING = "<<shortest_path(grid);
    cout<<"\nDIJKSHTRA = "<<shortest_path_djk(grid); // causing compilation error

    return 0;
}