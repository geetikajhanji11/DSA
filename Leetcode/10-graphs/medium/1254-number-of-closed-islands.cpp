/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool inBounds(int &i, int &j, vector<vector<int>>& grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size(); 
    }

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    void dfs(int i, int j, vector<vector<int>>& grid) {
        
        if(!inBounds(i, j, grid)) return;
        if(grid[i][j] == 1) return;

        // make 0 => 1 (visited)
        grid[i][j] = 1;

        for(int k=0; k<4; k++) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            dfs(next_i, next_j, grid);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // dfs over 0's at perimeter of grid
        // but do not count these occurences

        // top & bottom row
        for(int j=0; j<cols; j++) {
            if(grid[0][j] == 0) dfs(0, j, grid);
            if(grid[rows-1][j] == 0) dfs(rows-1, j, grid);
        }

        // left & right cols
        for(int i=0; i<rows; i++) {
            if(grid[i][0] == 0) dfs(i, 0, grid);
            if(grid[i][cols-1] == 0) dfs(i, cols-1, grid);
        }

        // dfs over all 0's, and this time,
        // count the occurences
        int islands = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 0) {
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }

        return islands;
    }
};