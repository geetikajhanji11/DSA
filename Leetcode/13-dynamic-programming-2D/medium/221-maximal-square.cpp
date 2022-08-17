/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************** TOP - DOWN APPROACH **************
bool in_bounds(int i, int j, vector<vector<char>>& matrix) {
    return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size();
}

int maxLength(int i, int j, vector<vector<char>>& matrix, vector<vector<int>> &dp) {
    if(!in_bounds(i, j, matrix)) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    // explore right, diagonal and down locations
    int rightMaxLen = maxLength(i, j+1, matrix, dp);
    int downMaxLen = maxLength(i+1, j, matrix, dp);
    int diagMaxLength = maxLength(i+1, j+1, matrix, dp);

    // calculate current cell's max length
    if(matrix[i][j] == '0') {
        dp[i][j] = 0;
    } else {
        dp[i][j] = 1 + min(diagMaxLength, min(rightMaxLen, downMaxLen));
    }

    return dp[i][j];
}

int maximalSquare(vector<vector<char>>& matrix) {

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    maxLength(0, 0, matrix, dp);

    int result = 0;
    for(vector<int> v : dp) {
        for(int num : v) {
            result = max(result, num);
        }
    }

    return result * result;
}


// ************** BOTTOM - UP APPROACH **************
// i,j  
// iterate from last row to top
// and right to left
int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    int result = 0;
    for(int i=rows-1; i>=0; i--) {
        for(int j=cols-1; j>=0; j--) {

            if(matrix[i][j] == '0') {
                dp[i][j] = 0;
                continue;
            }

            int rightMaxLen = j+1 < cols ? dp[i][j+1] : 0;
            int downMaxLen = i+1 < rows ? dp[i+1][j] : 0;
            int diagMaxLength = (i+1 < rows && j+1 < cols) ? dp[i+1][j+1] : 0;

            dp[i][j] = 1 + min(diagMaxLength, min(rightMaxLen, downMaxLen));
            result = max(result, dp[i][j]);
        }
    }

    return result * result;
}


int main() {

    return 0;
}