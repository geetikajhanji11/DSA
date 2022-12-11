/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ****************** TOP - DOWN ******************
class Solution {
    bool inBounds(int i, int j, vector<vector<int>> &grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    int minSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(!inBounds(i, j, grid)) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];
        
       int right = minSum(i, j+1, grid, dp);
       int down = minSum(i+1, j, grid, dp);
       int sum = grid[i][j] + min(right, down);

        return dp[i][j] = sum;

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minSum(0, 0, grid, dp);
    }
};


// ****************** BOTTOM - UP ******************
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        // fill up bottom row with suffix sum
        for(int j=cols-2; j>=0; j--) {
            grid[rows-1][j] += grid[rows-1][j+1];
        }

        // fill up rightmost col with suffix sum
        for(int i=rows-2; i>=0; i--) {
            grid[i][cols-1] += grid[i+1][cols-1];
        }

        // now traverse from bottom right to top left
        for(int i=rows-2; i>=0; i--) {
            for(int j=cols-2; j>=0; j--) {
                grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
            }
        }

        return grid[0][0];
    }
};