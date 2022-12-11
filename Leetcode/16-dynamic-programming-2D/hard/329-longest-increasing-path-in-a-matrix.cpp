/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool in_bounds(int i, int j, vector<vector<int>>& matrix) {
    return i >=0 && i < matrix.size() && j >= 0 && j < matrix[0].size();
}

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp) {

    if(dp[i][j] != -1) return dp[i][j];

    int longest_length = 0;
    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        if(!in_bounds(next_i, next_j, matrix)) continue;
        if(matrix[next_i][next_j] > matrix[i][j]) {
            longest_length = max(longest_length, dfs(next_i, next_j, matrix, dp));
        } 
    }

    return dp[i][j] = longest_length + 1;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    int longest_length = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int curr_length = dfs(i, j, matrix, dp);
            longest_length = max(longest_length, curr_length);
        }
    }

    return longest_length;
}

int main() {

    vector<vector<int>> matrix = {
        {3,4,5},
        {3,2,6},
        {2,2,1}
    };
    int ans = longestIncreasingPath(matrix);
    cout<<"ans = "<<ans;
    return 0;
}