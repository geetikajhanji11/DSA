/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *********** TOP - DOWN APPROACH ***********
int minTotal(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
    if(i == triangle.size()) return 0;
    if(j < 0 || j >= triangle[i].size()) return INT_MAX;

    if(dp[i][j] != INT_MAX) return dp[i][j];

    int next_row_down = minTotal(i+1, j, triangle, dp);
    int next_row_right = minTotal(i+1, j+1, triangle, dp);

    return dp[i][j] = triangle[i][j] + min(next_row_down, next_row_right);
}

int minimumTotal(vector<vector<int>>& triangle) {

    int rows = triangle.size();
    int cols = triangle[rows-1].size();

    vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
    return minTotal(0, 0, triangle, dp);
}

// *********** BOTTOM - UP APPROACH ***********
int minimumTotal(vector<vector<int>>& triangle) {
    int rows = triangle.size();
    int cols = triangle[rows-1].size();

    // insert all numbers in the last row of triangle matrix
    vector<int> dp_row;
    for(int num : triangle[rows-1]) {
        dp_row.push_back(num);
    }

    for(int i=rows-2; i>=0; i--) {
        int left = 0;
        int right = triangle[i].size() - 1;

        for(int j=left; j<=right; j++) {
            int next_row_down = dp_row[j];
            int next_row_right = j+1 <= triangle[i].size() ? dp_row[j+1] : INT_MAX;
            dp_row[j] = triangle[i][j] + min(next_row_down, next_row_right);
        }
    }

    return dp_row[0];
}

int main() {

    return 0;
}