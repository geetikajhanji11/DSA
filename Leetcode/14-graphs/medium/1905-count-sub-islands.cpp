/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    
public:

    bool inBounds(int i, int j, vector<vector<int>>& grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        if(!inBounds(i, j, grid2) || grid2[i][j] == 0) return true;

        bool result = true;

        // don't return immediately, 
        // because we stil want to visit entire island of grid2
        if(grid2[i][j] == 1 && grid1[i][j] == 0) {
            result = false; 
        }

        // current cell is 1
        // mark it as visited
        grid2[i][j] = 0;

        // 4 directions
        for(int k=0; k<4; k++) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            result = dfs(next_i, next_j, grid1, grid2) && result;
        }

        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int rows = grid2.size();
        int cols = grid2[0].size();

        int subIslands = 0;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                // detected an island
                if(grid2[i][j] == 1) {
                    if(dfs(i, j, grid1, grid2)) {
                        subIslands++;
                    }
                }
            }
        }

        return subIslands;
    }
};

int main() {

    return 0;
}