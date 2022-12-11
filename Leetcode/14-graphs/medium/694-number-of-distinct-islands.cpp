/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool inBounds(int &i, int &j, vector<vector<int>> &grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
 
    void dfs(int i, int j, int &x0, int &y0, vector<vector<int>> &grid, vector<pair<int, int>> &coordinates) {
        if(!inBounds(i, j, grid)) return;
        if(grid[i][j] == 0) return;

        grid[i][j] = 0;
        coordinates.push_back({i - x0, j - y0});

        for(int k=0; k<4; k++) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            dfs(next_i, next_j, x0, y0, grid, coordinates);
        }
    }

public:
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        
        set<vector<pair<int,int>>> uniqueCoordinateSet;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    vector<pair<int, int>> coordinates;
                    dfs(i, j, i, j, grid, coordinates);
                    uniqueCoordinateSet.insert(coordinates);
                }
            }
        }

        return uniqueCoordinateSet.size();
    }
};