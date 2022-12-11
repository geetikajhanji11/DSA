/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool inBounds(int i, int j, vector<vector<int>> &obstacleGrid) {
        return i >= 0 && i < obstacleGrid.size() && j >= 0 && j < obstacleGrid[0].size();
    }

    int uniquePaths(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
        if(!inBounds(i, j, obstacleGrid)) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(obstacleGrid[i][j] == 1) return 0;
        if(i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) return 1;
        
        int ans = 0;
        ans += uniquePaths(i+1, j, obstacleGrid, dp); // down
        ans += uniquePaths(i, j+1, obstacleGrid, dp); // right

        return dp[i][j] = ans;

    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePaths(0, 0, obstacleGrid, dp);
    }
};