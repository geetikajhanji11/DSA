/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool inBounds(int i, int j, vector<vector<int>>& matrix) {
        return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size(); 
    }

    int pathSum(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(!inBounds(i, j, matrix)) return INT_MAX;
        if(i == matrix.size() - 1) return matrix[i][j];

        if(dp[i][j] != INT_MAX) return dp[i][j]; 

        int leftSum = pathSum(i+1, j-1, matrix, dp);
        int midSum = pathSum(i+1, j, matrix, dp);
        int rightSum = pathSum(i+1, j+1, matrix, dp);
        int currSum = matrix[i][j] + min(leftSum, min(midSum, rightSum));

        return dp[i][j] = currSum; 
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));

        int result = INT_MAX;
        for(int col=0; col<cols; col++) {
            result = min(result, pathSum(0, col, matrix, dp));
        }

        return result;
    }
};