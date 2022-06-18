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
bool cellInBounds(int i, int j, int rows, int cols) {
    if(i >= 0 && i < rows && j >= 0 && j < cols) return true;
    return false;
}

int dfs(vector<vector<int> > grid, int i, int j, vector<vector<int>> &visited, int total_cost, int &min_cost) {

    // cell is not in bounds
    if(!cellInBounds(i, j, grid.size(), grid[0].size())) return 0;
    // cell already visited, do not traverse
    if(visited[i][j]) return 0;

    // get the current cost
    int current_cost = grid[i][j];

    // reached the destination
    if(i == grid.size() - 1 && j == grid[0].size() - 1) {
        if(total_cost + current_cost < min_cost) {
            min_cost = total_cost + current_cost;
        }
        return total_cost + current_cost;
    }

    // mark the current node as visited
    visited[i][j] = true;

    // 4 directions => up, down, left, right
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    // recursive call in each direction
    int cost;
    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        cost = dfs(grid, next_i, next_j, visited, total_cost + current_cost, min_cost);
    }

    // backtracking
    visited[i][j] = false;

    return cost;
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
class Node {
public:
    int x;
    int y;
    int distance;

    Node(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->distance = dist;
    }
};

//comparator should return boolean value, 
// indicating whether the element passed as 
// first argument is considered to go before 
// the second in the specific strict weak ordering 
class Compare {
    public:
    bool operator() (const Node &a, const Node &b) {
        return a.distance <= b.distance;
    }
};

int shortest_path_djk(vector<vector<int> > grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> distance(rows+1, vector<int>(cols+1, INT_MAX));
    set<Node, Compare> s;

    distance[0][0] = grid[0][0];
    s.insert(Node(0, 0, distance[0][0]));

    while(!s.empty()) {
        auto it = s.begin();

        int curr_x = it->x;
        int curr_y = it->y;
        int curr_distance = it->distance;

        s.erase(it);

        // 4 directions => up, down, left, right
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        for(int k=0; k<4; k++) {
            int next_x = curr_x + dx[k];
            int next_y = curr_y + dy[k];
            int new_distance = curr_distance + grid[next_x][next_y];
            if(cellInBounds(next_x, next_y, rows, cols) && new_distance < distance[next_x][next_y]) {

                // if the next node already exists in set
                // erase it
                Node temp(next_x, next_y, distance[next_x][next_y]);
                if(s.find(temp) != s.end()) {
                    s.erase(s.find(temp));
                } 

                // insert next node in set and update distance vector
                distance[next_x][next_y] = new_distance;
                s.insert(Node(next_x, next_y, new_distance));
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