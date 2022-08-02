/*******************************************************************
 * LONGEST INCREASING PATH IN MATRIX
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cellInBounds(int i, int j, vector<vector<int>> &matrix) {
    return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size();
}

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

int longestPath(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {

    if(dp[i][j] != -1) return dp[i][j];

    int longest = 1;
    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(!cellInBounds(next_i, next_j, matrix)) continue;

        if(matrix[next_i][next_j] > matrix[i][j]) {
            int remainingLongestPath = longestPath(next_i, next_j, matrix, dp);
            longest = max(longest, 1 + remainingLongestPath);
        }
    }

    return dp[i][j] = longest;
}

int longestPathSequence(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    int longest = 1;
    int start_i = 0;
    int start_j = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int curr_longest = longestPath(i, j, matrix, dp);
            if(curr_longest > longest) {
                longest = curr_longest;
                start_i = i;
                start_j = j;
            }
            
        }
    }

    cout<<"\nStarts at i = "<<start_i<<", j = "<<start_j;
    return longest;
}

int main() {

    vector<vector<int>> grid = {
        {0,  2,  4,  3,  2},
        {7,  6,  5,  5,  1},
        {8,  9,  7, 18, 14},
        {5, 10, 11, 12, 13},
    };

    int longest = longestPathSequence(grid);
    cout<<"\nlength = "<<longest;
    return 0;
}