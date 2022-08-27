/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // generate prefix sum array (for top row)
    vector<long long> getPrefixSum(vector<vector<int>> &grid, int i) {
        int n = grid[i].size();
        vector<long long> row(n);
        row[0] = grid[i][0];
        for(int j=1; j<n; j++) {
            row[j] = grid[i][j] + row[j-1];
        }
        return row;
    }

public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        // prefix sum of both rows
        vector<long long> prefixTopRow = getPrefixSum(grid, 0);
        vector<long long> prefixBottomRow = getPrefixSum(grid, 1);

        long long result = LONG_LONG_MAX;
        for(int i=0; i<n; i++) {
            long long top = prefixTopRow[n-1] - prefixTopRow[i];
            long long bottom = i-1 >= 0 ? prefixBottomRow[i-1] : 0;
            long long secondRobot = max(top, bottom);

            result = min(result, secondRobot);
        }

        return result;
    }

};