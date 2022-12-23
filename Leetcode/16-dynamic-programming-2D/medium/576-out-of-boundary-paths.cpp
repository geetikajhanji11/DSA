/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int MOD = pow(10, 9) + 7;

    bool inBounds(int i, int j, int &m, int &n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};

    int allPathsOutOfBounds(int i, int j, int moves, int &m, int &n, vector<vector<vector<int>>> &dp) {
        if(moves < 0) return 0;

        if(!inBounds(i, j, m, n)) {
            return 1;
        }

        if(dp[i][j][moves] != -1) return dp[i][j][moves];

        int paths = 0;
        for(int k=0; k<4; k++) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            paths += allPathsOutOfBounds(next_i, next_j, moves-1, m, n, dp);
            paths = paths % MOD;
        }

        return dp[i][j][moves] = paths % MOD;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return allPathsOutOfBounds(startRow, startColumn, maxMove, m, n, dp);      
    }
};